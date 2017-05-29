/*------------------------------------------------------------------------------

   MiniLight C++ : minimal global illumination renderer
   Harrison Ainsworth / HXA7241 : 2006-2011, 2013

   http://www.hxa.name/minilight

------------------------------------------------------------------------------*/

#ifndef SurfacePoint_h
#define SurfacePoint_h

#include "vector3f.h"
#include "hxa7241_minilight.h"

namespace hxa7241_minilight
{

/**
 * Surface point at a ray-object intersection.<br/><br/>
 *
 * All direction parameters are away from surface.<br/><br/>
 *
 * Constant.<br/><br/>
  *
 * @invariants
 * * pTriangle_m points to a Triangle (is not 0)
*/
class SurfacePoint
{
 public:
  SurfacePoint( const Triangle& triangle, const Vector3f& position );

  Vector3f getEmission( const Vector3f& toPosition,
			const Vector3f& outDirection,
			const bool      isSolidAngle ) const;
  Vector3f getReflection( const Vector3f& inDirection,
			  const Vector3f& inRadiance,
			  const Vector3f& outDirection ) const;
  bool     getNextDirection( const Random&    random,
			     const Vector3f&  inDirection,
			     Vector3f&        outDirection_o,
			     Vector3f&        color_o ) const;

  const void* getHitId() const;
  Vector3f    getPosition() const;

 private:
  const Triangle* pTriangle_m;
  Vector3f        position_m;
};

}//namespace

#endif//SurfacePoint_h
