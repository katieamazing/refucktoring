/*------------------------------------------------------------------------------

   MiniLight C++ : minimal global illumination renderer
   Harrison Ainsworth / HXA7241 : 2006-2011, 2013

   http://www.hxa.name/minilight

------------------------------------------------------------------------------*/


#include <math.h>
#include <istream>

#include "random.h"
#include "triangle.h"

using namespace hxa7241_minilight;

namespace
{
   // reasonable for single precision FP
   const real64 EPSILON = 1.0 / 1048576.0;
}

Triangle::Triangle
(
   std::istream& in
)
{
   // read geometry
   for( int i = 0;  i < 3;  in >> vertexs_m[i++] ) {}

   // read and condition quality
   {
      in >> reflectivity_m;
      reflectivity_m = reflectivity_m.getClamped(
         Vector3f::ZERO(), Vector3f::ONE() );

      in >> emitivity_m;
      emitivity_m = emitivity_m.getClamped( Vector3f::ZERO(), Vector3f::MAX() );
   }
}

void Triangle::getBound
(
   real64 bound[6]
) const
{
   // initialize
   for( int i = 6;  i-- > 0;  bound[i] = vertexs_m[2][i % 3] ) {}

   // expand
   for( int i = 0;  i < 3;  ++i )
   {
      for( int j = 0, d = 0, m = 0;  j < 6;  ++j, d = j / 3, m = j % 3 )
      {
         // include some tolerance
         const real64 v = vertexs_m[i][m] + ((d ? 1.0 : -1.0) * TOLERANCE());
         bound[j] = (bound[j] > v) ^ d ? v : bound[j];
      }
   }
}


/**
 * @implementation
 * Adapted from:
 * <cite>'Fast, Minimum Storage Ray-Triangle Intersection'
 * Moller, Trumbore;
 * Journal Of Graphics Tools, v2n1p21, 1997.
 * http://www.acm.org/jgt/papers/MollerTrumbore97/</cite>
 */
bool Triangle::getIntersection
(
   const Vector3f& rayOrigin,
   const Vector3f& rayDirection,
   real64&         hitDistance_o
) const
{
   // find vectors for two edges sharing vert0
   const Vector3f edge1( vertexs_m[1] - vertexs_m[0] );
   const Vector3f edge2( vertexs_m[2] - vertexs_m[0] );

   // begin calculating determinant - also used to calculate U parameter
   const Vector3f pvec( rayDirection.cross( edge2 ) );

   // if determinant is near zero, ray lies in plane of triangle
   const real64 det = edge1.dot( pvec );

   bool isHit = false;
   if( (det <= -EPSILON) | (det >= EPSILON) )
   {
      const real64 inv_det = 1.0 / det;

      // calculate distance from vertex 0 to ray origin
      const Vector3f tvec( rayOrigin - vertexs_m[0] );

      // calculate U parameter and test bounds
      const real64 u = tvec.dot( pvec ) * inv_det;
      if( (u >= 0.0) & (u <= 1.0) )
      {
         // prepare to test V parameter
         const Vector3f qvec( tvec.cross( edge1 ) );

         // calculate V parameter and test bounds
         const real64 v = rayDirection.dot( qvec ) * inv_det;
         if( (v >= 0.0) & (u + v <= 1.0) )
         {
            // calculate t, ray intersects triangle
            hitDistance_o = edge2.dot( qvec ) * inv_det;

            // only allow intersections in the forward ray direction
            isHit = (hitDistance_o >= 0.0);
         }
      }
   }
   return isHit;
}


Vector3f Triangle::getSamplePoint
(
   const Random& random
) const
{
   // get two randoms
   const real64 sqr1 = ::sqrt( random.getReal64() );
   const real64 r2   = random.getReal64();

   // make barycentric coords
   const real64 a = 1.0 - sqr1;
   const real64 b = (1.0 - r2) * sqr1;
   //const real64 c = r2 * sqr1;

   // make position from barycentrics
   // calculate interpolation by using two edges as axes scaled by the
   // barycentrics
   return Vector3f( ((vertexs_m[1] - vertexs_m[0]) * a) +
      ((vertexs_m[2] - vertexs_m[0]) * b) + vertexs_m[0] );
}

Vector3f Triangle::getNormal() const
{
   return getTangent().cross( vertexs_m[2] - vertexs_m[1] ).unitize();
}

Vector3f Triangle::getTangent() const
{
   return (vertexs_m[1] - vertexs_m[0]).unitize();
}

real64 Triangle::getArea() const
{
   // half area of parallelogram
   const Vector3f pa2( (vertexs_m[1] - vertexs_m[0]).cross(
      vertexs_m[2] - vertexs_m[1] ) );
   return ::sqrt( pa2.dot(pa2) ) * 0.5;
}

Vector3f Triangle::getReflectivity() const
{
   return reflectivity_m;
}

Vector3f Triangle::getEmitivity() const
{
   return emitivity_m;
}

real64 Triangle::TOLERANCE()
{
   // one mm seems reasonable...
   return 1.0 / 1024.0;
}
