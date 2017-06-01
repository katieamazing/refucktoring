/*------------------------------------------------------------------------------

   MiniLight C++ : minimal global illumination renderer
   Harrison Ainsworth / HXA7241 : 2006-2011, 2013

   http://www.hxa.name/minilight

------------------------------------------------------------------------------*/

#ifndef Scene_h
#define Scene_h

#include <iosfwd>
#include <vector>

#include "vector3f.h"
#include "triangle.h"
#include "hxa7241_minilight.h"

namespace hxa7241_minilight
{

/**
 * Collection of objects in the environment.<br/><br/>
 *
 * Makes a sub-grouping of emitting objects.<br/><br/>
 *
 * Constant.
 *
 * @invariants
 * * triangles_m.size() <= TRIANGLES_MAX
 * * emitters_m.size()  <= TRIANGLES_MAX
 * * pIndex_m is a non-zero pointer to a SpatialIndex
 * * skyEmission_m      >= 0
 * * groundReflection_m >= 0
 */
class Scene
{
 public:
  Scene( std::istream&, const Vector3f& eyePosition );
  ~Scene();
 private:
  Scene( const Scene& );
  Scene& operator=( const Scene& );
 public:
  void getIntersection( const Vector3f&  rayOrigin,
			const Vector3f&  rayDirection,
			const void*      lastHit,
			const Triangle*& pHitObject_o,
			Vector3f&        hitPosition_o ) const;
  void getEmitter( const Random&    random,
		   Vector3f&        position_o,
		   const Triangle*& id_o ) const;
  int32 getEmittersCount() const;
  Vector3f getDefaultEmission( const Vector3f& backDirection ) const;
  static int32 TRIANGLES_MAX();
 private:
  std::vector<Triangle>        triangles_m;
  std::vector<const Triangle*> emitters_m;
  const SpatialIndex*          pIndex_m;

  Vector3f skyEmission_m;
  Vector3f groundReflection_m;
};

}//namespace

#endif//Scene_h
