/*------------------------------------------------------------------------------

   MiniLight C++ : minimal global illumination renderer
   Harrison Ainsworth / HXA7241 : 2006-2011, 2013

   http://www.hxa.name/minilight

------------------------------------------------------------------------------*/


#include "vector3f.h"
#include "scene.h"
#include "surface_point.h"

#include "ray_tracer.h"


using namespace hxa7241_minilight;




/// standard object services ---------------------------------------------------

RayTracer::RayTracer
(
   const Scene& scene
)
 : pScene_m( &scene )
{
}




/// queries --------------------------------------------------------------------

Vector3f RayTracer::getRadiance
(
   const Vector3f& rayOrigin,
   const Vector3f& rayDirection,
   const Random&   random,
   const void*     lastHit
) const
{
   // intersect ray with scene
   const Triangle* pHitObject = 0;
   Vector3f        hitPosition;
   pScene_m->getIntersection( rayOrigin, rayDirection, lastHit,
      pHitObject, hitPosition );

   Vector3f radiance;
   if( 0 != pHitObject )
   {
      // make surface point of intersection
      SurfacePoint surfacePoint( *pHitObject, hitPosition );

      // local emission only for first-hit
      radiance = ( 0 != lastHit ? Vector3f::ZERO() :
         surfacePoint.getEmission( rayOrigin, -rayDirection, false ) );

      // add emitter sample
      radiance = radiance + sampleEmitters( rayDirection, surfacePoint, random);

      // add recursive reflection
      //
      // single hemisphere sample, ideal diffuse BRDF:
      //    reflected = (inradiance * pi) * (cos(in) / pi * color) *
      //       reflectance
      // -- reflectance magnitude is 'scaled' by the russian roulette,
      // cos is importance sampled (both done by SurfacePoint),
      // and the pi and 1/pi cancel out -- leaving just:
      //    inradiance * reflectance color
      Vector3f nextDirection;
      Vector3f color;
      // check surface reflects ray
      if( surfacePoint.getNextDirection( random, -rayDirection,
         nextDirection, color ) )
      {
         // recurse
         radiance = radiance + (color * getRadiance( surfacePoint.getPosition(),
            nextDirection, random, surfacePoint.getHitId() ));
      }
   }
   else
   {
      // no hit: default/background scene emission
      radiance = pScene_m->getDefaultEmission( -rayDirection );
   }

   return radiance;
}




/// implementation -------------------------------------------------------------

Vector3f RayTracer::sampleEmitters
(
   const Vector3f&     rayDirection,
   const SurfacePoint& surfacePoint,
   const Random&       random
) const
{
   Vector3f radiance;

   // single emitter sample, ideal diffuse BRDF:
   //    reflected = (emitivity * solidangle) * (emitterscount) *
   //       (cos(emitdirection) / pi * reflectivity)
   // -- SurfacePoint does the first and last parts (in separate methods)

   // get position on an emitter
   Vector3f        emitterPosition;
   const Triangle* emitterId = 0;
   pScene_m->getEmitter( random, emitterPosition, emitterId );

   // check an emitter was found
   if( 0 != emitterId )
   {
      // make direction to emit point
      const Vector3f emitDirection( (emitterPosition -
         surfacePoint.getPosition()).unitize() );

      // send shadow ray
      const Triangle* pHitObject = 0;
      Vector3f        hitPosition;
      pScene_m->getIntersection( surfacePoint.getPosition(), emitDirection,
         surfacePoint.getHitId(), pHitObject, hitPosition );

      // if unshadowed, get inward emission value
      Vector3f emissionIn;
      if( (0 == pHitObject) | (emitterId == pHitObject) )
      {
         emissionIn = SurfacePoint( *emitterId, emitterPosition ).getEmission(
            surfacePoint.getPosition(), -emitDirection, true );
      }

      // get amount reflected by surface
      radiance = surfacePoint.getReflection( emitDirection, emissionIn *
         static_cast<real64>(pScene_m->getEmittersCount()), -rayDirection );
   }

   return radiance;
}
