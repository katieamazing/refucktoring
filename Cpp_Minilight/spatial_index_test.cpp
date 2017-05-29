#include "catch.h"
#include "spatial_index.h"
#include "vector3f.h"
#include "triangle.h"

using namespace hxa7241_minilight;
using namespace hxa7241_graphics;

SCENARIO( "An empty world", "[spatial_index]" ) {
  Vector3f eye_position(0.0, 0.0, 0.0);
  std::vector<Triangle> items;
  SpatialIndex to_test(eye_position, items);
  /*
WHEN( "getIntersection is called" ) {
}
  */
}

