#include "catch.h"
#include "spatial_index.h"
#include "vector3f.h"
#include "triangle.h"

using namespace hxa7241_minilight;
using namespace hxa7241_graphics;

SCENARIO( "Smits large", "[spatial_index]" ) {
  Vector3f eye_position(0.0, 0.650, -1.273);
  std::stringstream to_parse(
    "(-20 0 -20) (-20 0 20) (20 0 -20)  (0.75 0.75 0.75) (0 0 0)\n"
    "( 20 0 -20) (-20 0 20) (20 0  20)  (0.75 0.75 0.75) (0 0 0)\n"
    "(-0.05 0.15 -0.05) (-0.05 0.15 0.05) ( 0.05 0.15 -0.05)  (0.75 0.75 0.75) (0 0 0)\n"
    "( 0.05 0.15 -0.05) (-0.05 0.15 0.05) ( 0.05 0.15  0.05)  (0.75 0.75 0.75) (0 0 0)\n"
    "(-0.05 0.4  -0.05) ( 0.05 0.4 -0.05) (-0.05 0.4   0.05)  (0 0 0) (500 500 500)\n"
    "(-0.05 0.4   0.05) ( 0.05 0.4 -0.05) ( 0.05 0.4   0.05)  (0 0 0) (500 500 500)\n"
    "(-0.5  0.5 -0.5) (-0.5  0.5  0.5) ( 0.5  0.5 -0.5)  (0.75 0.75 0.75) (0 0 0)\n"
    "( 0.5  0.5 -0.5) (-0.5  0.5  0.5) ( 0.5  0.5  0.5)  (0.75 0.75 0.75) (0 0 0)\n"
    "(-0.5 10.5 -0.5) ( 0.5 10.5 -0.5) (-0.5 10.5  0.5)  (0 0 0) (5000 5000 5000)\n"
    "(-0.5 10.5  0.5) ( 0.5 10.5 -0.5) ( 0.5 10.5  0.5)  (0 0 0) (5000 5000 5000)\n");

  vector<Triangle> items_vector;
  for (int i = 0; i < 10; i++) {
    items_vector.push_back(Triangle(to_parse));
  }
  SpatialIndex to_test(eye_position, items_vector);
  /*
WHEN( "getIntersection is called" ) {
}
  */
}

