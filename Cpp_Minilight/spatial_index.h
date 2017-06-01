/*------------------------------------------------------------------------------

   MiniLight C++ : minimal global illumination renderer
   Harrison Ainsworth / HXA7241 : 2006-2011, 2013

   http://www.hxa.name/minilight

------------------------------------------------------------------------------*/

#ifndef SpatialIndex_h
#define SpatialIndex_h

#include <vector>
#include "hxa7241_minilight.h"

namespace hxa7241_minilight
{
   using std::vector;

/**
 * A minimal spatial index for ray tracing.<br/><br/>
 *
 * Suitable for a scale of 1 metre == 1 numerical unit, and has a resolution of
 * 1 millimetre. (Implementation uses fixed tolerances.)
 *
 * Constant.<br/><br/>
 *
 * @implementation
 * A crude State pattern: typed by isBranch_m field to be either a branch
 * or leaf cell.<br/><br/>
 *
 * Octree: axis-aligned, cubical. Subcells are numbered thusly:
 * <pre>      110---111
 *            /|    /|
 *         010---011 |
 *    y z   | 100-|-101
 *    |/    |/    | /
 *    .-x  000---001      </pre><br/><br/>
 *
 * Each cell stores its bound: fatter data, but simpler code.<br/><br/>
 *
 * Calculations for building and tracing are absolute rather than incremental --
 * so quite numerically solid. Uses tolerances in: bounding triangles (in
 * Triangle::getBound), and checking intersection is inside cell (both effective
 * for axis-aligned items). Also, depth is constrained to an absolute subcell
 * size (easy way to handle overlapping items).
 *
 * @invariants
 * * bound_m[0-2] <= bound_m[3-5]
 * * bound_m encompasses the cell's contents
 * if isBranch_m
 * * vector_m length is 8
 * * vector_m elements are zero or SpatialIndex pointers
 * else
 * * vector_m elements are non-zero Triangle pointers
 */
class SpatialIndex {
 public:
  SpatialIndex( const Vector3f& eyePosition, const vector<Triangle>& items );
  ~SpatialIndex();
 private:
  SpatialIndex( const SpatialIndex& );
  SpatialIndex& operator=( const SpatialIndex& );
 public:
  void getIntersection( const Vector3f&  rayOrigin,
			const Vector3f&  rayDirection,
			const void*      lastHit,
			const Triangle*& pHitObject_o,
			Vector3f&        hitPosition_o,
			const Vector3f*  pStart = 0 ) const;

 protected:
  SpatialIndex( const real64 bound[6] );
  const SpatialIndex* construct( const vector<const Triangle*>& items,
				 int32                          level);

 private:
  bool                isBranch_m;
  real64              bound_m[6];
  vector<const void*> vector_m;
};

}//namespace

#endif//SpatialIndex_h
