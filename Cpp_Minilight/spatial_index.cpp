/*------------------------------------------------------------------------------

   MiniLight C++ : minimal global illumination renderer
   Harrison Ainsworth / HXA7241 : 2006-2011, 2013

   http://www.hxa.name/minilight

------------------------------------------------------------------------------*/


#include "vector3f.h"
#include "triangle.h"

#include "spatial_index.h"


using namespace hxa7241_minilight;




/// constants ------------------------------------------------------------------

namespace
{
   // accommodates scene including sun and earth, down to cm cells
   // (use 47 for mm)
   const int32  MAX_LEVELS = 44;
   const int32u MAX_ITEMS  =  8;
}




/// standard object services ---------------------------------------------------

SpatialIndex::SpatialIndex
(
   const Vector3f&         eyePosition,
   const vector<Triangle>& items
)
{
   // set overall bound (and convert to collection of pointers)
   vector<const Triangle*> itemPs( items.size() );
   {
      // accommodate eye position
      // (makes tracing algorithm simpler)
      for( int i = 6;  i-- > 0;  bound_m[i] = eyePosition[i % 3] ) {}

      // accommodate all items
      for( int32u i = 0;  i < items.size();  itemPs[i] = &(items[i]), ++i )
      {
         real64 itemBound[6];
         items[i].getBound( itemBound );

         // accommodate item
         for( int j = 0;  j < 6;  ++j )
         {
            if((bound_m[j] > itemBound[j]) ^ (j > 2)) bound_m[j] = itemBound[j];
         }
      }

      // make cubical
      real64 maxSize = 0.0;
      for( const real64* b = bound_m + 3;  b-- > bound_m; )
      {
         if( maxSize < (b[3] - b[0]) ) maxSize = b[3] - b[0];
      }
      for( real64* b = bound_m + 3;  b-- > bound_m; )
      {
         if( b[3] < (b[0] + maxSize) ) b[3] = b[0] + maxSize;
      }
   }

   // make cell tree
   SpatialIndex::construct( itemPs, 0 );
}


SpatialIndex::SpatialIndex
(
   const real64 bound[6]
)
{
   for( int i = 6;  i-- > 0;  bound_m[i] = bound[i] ) {}
}


SpatialIndex::~SpatialIndex()
{
   // only delete branch sub-parts
   for( int32u i = 0;  isBranch_m & (i < vector_m.size());  ++i )
   {
      delete static_cast<const SpatialIndex*>( vector_m[i] );
   }
}




/// commands -------------------------------------------------------------------




/// queries --------------------------------------------------------------------

void SpatialIndex::getIntersection
(
   const Vector3f&  rayOrigin,
   const Vector3f&  rayDirection,
   const void*      lastHit,
   const Triangle*& pHitObject_o,
   Vector3f&        hitPosition_o,
   const Vector3f*  pStart
) const
{
   // is branch: step through subcells and recurse
   if( isBranch_m )
   {
      pStart = pStart ? pStart : &rayOrigin;

      // find which subcell holds ray origin (ray origin is inside cell)
      int32 subCell = 0;
      for( int i = 3;  i-- > 0; )
      {
         // compare dimension with center
         subCell |= ((*pStart)[i] >= ((bound_m[i] + bound_m[i+3]) * 0.5)) << i;
      }

      // step through intersected subcells
      for( Vector3f cellPosition( *pStart );  ; )
      {
         if( 0 != vector_m[static_cast<int32u>(subCell)] )
         {
            // intersect subcell
            static_cast<const SpatialIndex*>( vector_m[static_cast<int32u>(
               subCell)] )->getIntersection( rayOrigin, rayDirection, lastHit,
                  pHitObject_o, hitPosition_o, &cellPosition );
            // exit if item hit
            if( 0 != pHitObject_o ) break;
         }

         // find next subcell ray moves to
         // (by finding which face of the corner ahead is crossed first)
         int32 axis = 2;
         real64 step[3];
         for( int i = 3;  i-- > 0;  axis = step[i] < step[axis] ? i : axis )
         {
            const int32  high = (subCell >> i) & 1;
            const real64 face = (rayDirection[i] < 0.0) ^ high ?
               bound_m[i + (high * 3)] : (bound_m[i] + bound_m[i + 3]) * 0.5;
            // distance to face
            // (div by zero produces infinity, which is later discarded)
            step[i] = (face - rayOrigin[i]) / rayDirection[i];
         }

         // leaving branch if: subcell is low and direction is negative,
         // or subcell is high and direction is positive
         if( ((subCell >> axis) & 1) ^ (rayDirection[axis] < 0.0) ) break;

         // move to (outer face of) next subcell
         cellPosition = rayOrigin + (rayDirection * step[axis]);
         subCell      = subCell ^ (1 << axis);
      }
   }
   // is leaf: exhaustively intersect contained items
   else
   {
      pHitObject_o = 0;

      real64 nearestDistance = REAL64_MAX;

      // step through items
      for( int32u i = 0;  i < vector_m.size();  ++i )
      {
         const Triangle& item = *static_cast<const Triangle*>(vector_m[i]);

         // avoid spurious intersection with surface just come from
         if( &item != lastHit )
         {
            // intersect ray with item, and inspect if nearest so far
            real64 distance = REAL64_MAX;
            if( item.getIntersection( rayOrigin, rayDirection, distance ) &&
               (distance < nearestDistance) )
            {
               // check intersection is inside cell bound (with tolerance)
               const Vector3f hit( rayOrigin + (rayDirection * distance) );
               const real64 t = Triangle::TOLERANCE();
               if( (bound_m[0] - hit[0] <= t) & (hit[0] - bound_m[3] <= t) &
                   (bound_m[1] - hit[1] <= t) & (hit[1] - bound_m[4] <= t) &
                   (bound_m[2] - hit[2] <= t) & (hit[2] - bound_m[5] <= t) )
               {
                  pHitObject_o    = &item;
                  nearestDistance = distance;
                  hitPosition_o   = hit;
               }
            }
         }
      }
   }
}




/// implementation -------------------------------------------------------------

const SpatialIndex* SpatialIndex::construct
(
   const vector<const Triangle*>& items,
   const int32                    level
)
{
   // is branch if items overflow leaf and tree not too deep
   isBranch_m = (items.size() > MAX_ITEMS) & (level < (MAX_LEVELS - 1));

   // be branch: make sub-cells, and recurse construction
   if( isBranch_m )
   {
      // make subcells
      vector_m.resize( 8 );
      for( int32u s = 0u, q = 0u;  s < vector_m.size();  ++s )
      {
         // make subcell bound
         // collect items that overlap subcell
         real64 subBound[6] = {};
         vector<const Triangle*> subItems;
         for( int32u i = 0;  i < items.size();  ++i )
         {
            real64 itemBound[6];
            items[i]->getBound( itemBound );

            int isOverlap = 1;
            // step through two coord sets
            for( int j = 0, d = 0, m = 0;  j < 6;  ++j, d = j / 3, m = j % 3 )
            {
               // make subcell bound
               subBound[j] = ((static_cast<int32>(s) >> m) & 1) ^ d ?
                  (bound_m[m] + bound_m[m + 3]) * 0.5 : bound_m[j];
               // must overlap in all dimensions
               isOverlap &= (itemBound[(d ^ 1) * 3 + m] >= subBound[j]) ^ d;
            }

            if( isOverlap ) subItems.push_back( items[i] );
         }

         // curtail degenerate subdivision by adjusting next level
         // (degenerate if two or more subcells copy entire contents of parent,
         // or if subdivision reaches below mm size)
         // (having a model including the sun requires one subcell copying
         // entire contents of parent to be allowed)
         q += subItems.size() == items.size() ? 1u : 0u;
         const int32 nextLevel = (q > 1u) | ((subBound[3] - subBound[0]) <
            (Triangle::TOLERANCE() * 4.0)) ? MAX_LEVELS : level + 1;

         // recurse
         vector_m[s] = !subItems.empty() ? (new SpatialIndex( subBound )
            )->construct( subItems, nextLevel ) : 0;
      }
   }
   // be leaf: store items
   else
   {
      // (trim reserve capacity, since vector_m was default-empty)
      vector_m = *reinterpret_cast<const vector<const void*>*>( &items );
   }

   return this;
}
