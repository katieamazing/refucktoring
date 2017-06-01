/*------------------------------------------------------------------------------

   MiniLight C++ : minimal global illumination renderer
   Harrison Ainsworth / HXA7241 : 2006-2011, 2013

   http://www.hxa.name/minilight

------------------------------------------------------------------------------*/


#include <math.h>

#include "random.h"
#include "triangle.h"

#include "surface_point.h"


using namespace hxa7241_minilight;




/// constants ------------------------------------------------------------------

namespace
{
   const real64 PI = 3.14159265358979;
}




/// standard object services ---------------------------------------------------

SurfacePoint::SurfacePoint
(
   const Triangle& triangle,
   const Vector3f& position
)
 : pTriangle_m( &triangle )
 , position_m ( position )
{
}




/// queries --------------------------------------------------------------------

Vector3f SurfacePoint::getEmission
(
   const Vector3f& toPosition,
   const Vector3f& outDirection,
   const bool      isSolidAngle
) const
{
   const Vector3f ray( toPosition - position_m );
   const real64   distance2 = ray.dot( ray );
   const real64   cosArea   = outDirection.dot( pTriangle_m->getNormal() ) *
      pTriangle_m->getArea();

   // with infinity clamped out
   const real64 solidAngle = isSolidAngle ?
      cosArea / (distance2 >= 1e-6 ? distance2 : 1e-6) : 1.0;

   // emit from front face of surface only
   return Vector3f( cosArea > 0.0 ?
      pTriangle_m->getEmitivity() * solidAngle : Vector3f::ZERO() );
}


Vector3f SurfacePoint::getReflection
(
   const Vector3f& inDirection,
   const Vector3f& inRadiance,
   const Vector3f& outDirection
) const
{
   const real64 inDot  = inDirection.dot(  pTriangle_m->getNormal() );
   const real64 outDot = outDirection.dot( pTriangle_m->getNormal() );

   // directions must be on same side of surface (no transmission)
   return Vector3f( (inDot < 0.0) ^ (outDot < 0.0) ? Vector3f::ZERO() :
      // ideal diffuse BRDF:
      // radiance scaled by reflectivity, cosine, and 1/pi
      (inRadiance * pTriangle_m->getReflectivity()) * (::fabs( inDot ) / PI) );
}


bool SurfacePoint::getNextDirection
(
   const Random&   random,
   const Vector3f& inDirection,
   Vector3f&       outDirection_o,
   Vector3f&       color_o
) const
{
   outDirection_o = Vector3f::ZERO();

   const real64 reflectivityMean =
      pTriangle_m->getReflectivity().dot( Vector3f::ONE() ) / 3.0;

   // russian-roulette for reflectance magnitude
   if( random.getReal64() < reflectivityMean )
   {
      // cosine-weighted importance sample hemisphere

      const real64 _2pr1 = PI * 2.0 * random.getReal64();
      const real64 sr2   = ::sqrt( random.getReal64() );

      // make coord frame coefficients (z in normal direction)
      const real64 x = ::cos( _2pr1 ) * sr2;
      const real64 y = ::sin( _2pr1 ) * sr2;
      const real64 z = ::sqrt( 1.0 - (sr2 * sr2) );

      // make coord frame
      Vector3f normal ( pTriangle_m->getNormal()  );
      Vector3f tangent( pTriangle_m->getTangent() );
      // put normal on inward ray side of surface (preventing transmission)
      normal = normal.dot( inDirection ) >= 0.0 ? normal : -normal;

      // make vector from frame scaled by coefficients
      outDirection_o = (tangent * x) + (normal.cross( tangent ) * y) +
         (normal * z);

      // make color by dividing-out mean from reflectivity
      color_o = pTriangle_m->getReflectivity() / reflectivityMean;
   }

   return !outDirection_o.isZero();
}


const void* SurfacePoint::getHitId() const
{
   return pTriangle_m;
}


Vector3f SurfacePoint::getPosition() const
{
   return position_m;
}
