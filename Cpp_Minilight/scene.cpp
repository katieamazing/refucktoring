/*------------------------------------------------------------------------------

   MiniLight C++ : minimal global illumination renderer
   Harrison Ainsworth / HXA7241 : 2006-2011, 2013

   http://www.hxa.name/minilight

------------------------------------------------------------------------------*/


#include <math.h>
#include <istream>

#include "random.h"
#include "spatial_index.h"
#include "scene.h"

using namespace hxa7241_minilight;

Scene::Scene
(
   std::istream&   in,
   const Vector3f& eyePosition
)
{
   // read and condition default sky and ground values
   in >> skyEmission_m >> groundReflection_m;

   skyEmission_m = skyEmission_m.getClamped( Vector3f::ZERO(), skyEmission_m );
   groundReflection_m = skyEmission_m * groundReflection_m.getClamped(
      Vector3f::ZERO(), Vector3f::ONE() );

   // read objects
   try
   {
      for( int32 i = 0;  i < TRIANGLES_MAX();  ++i )
      {
         triangles_m.push_back( Triangle( in ) );
      }
   }
   // EOF is not really exceptional here, but the code is much simpler.
   catch( ... )
   {
      if( !in.eof() ) throw;
   }

   // find emitting triangles
   for( int32u i = 0;  i < triangles_m.size();  ++i )
   {
      // has non-zero emission and area
      if( !triangles_m[i].getEmitivity().isZero() &&
         (triangles_m[i].getArea() > 0.0) )
      {
         emitters_m.push_back( &(triangles_m[i]) );
      }
   }

   // make index
   pIndex_m = new SpatialIndex( eyePosition, triangles_m );
}

Scene::~Scene()
{
   delete pIndex_m;
}

void Scene::getIntersection
(
   const Vector3f&  rayOrigin,
   const Vector3f&  rayDirection,
   const void*      lastHit,
   const Triangle*& pHitObject_o,
   Vector3f&        hitPosition_o
) const
{
   pIndex_m->getIntersection( rayOrigin, rayDirection, lastHit,
      pHitObject_o, hitPosition_o );
}


void Scene::getEmitter
(
   const Random&    random,
   Vector3f&        position_o,
   const Triangle*& id_o
) const
{
   if( !emitters_m.empty() )
   {
      // select emitter
      int32u index = static_cast<int32u>(::floor( random.getReal64() *
         static_cast<real64>(emitters_m.size()) ));
      index = index < emitters_m.size() ? index : int32u(emitters_m.size() -1u);

      // choose position on triangle
      position_o = emitters_m[ index ]->getSamplePoint( random );
      id_o       = emitters_m[ index ];
   }
   else
   {
      position_o = Vector3f::ZERO();
      id_o       = 0;
   }
}


int32 Scene::getEmittersCount() const
{
   return static_cast<int32>(emitters_m.size());
}


Vector3f Scene::getDefaultEmission
(
   const Vector3f& backDirection
) const
{
   // sky for downward ray, ground for upward ray
   return (backDirection[1] < 0.0) ? skyEmission_m : groundReflection_m;
}




/// constants ------------------------------------------------------------------

int32 Scene::TRIANGLES_MAX()
{
   // 2^24 ~= 16 million
   return 0x1000000;
}
