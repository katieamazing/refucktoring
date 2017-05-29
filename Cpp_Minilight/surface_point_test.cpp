#include "catch.h"
#include "surface_point.h"
#include "triangle.h"

using namespace hxa7241_minilight;
using namespace hxa7241_graphics;

SCENARIO( "???", "[surface_point]" ) {
  Vector3f position;
  std::istringstream triangle_description("(0 0 0) (0 1 0) (1 1 0) (0.7 0.7 0.7) (0 0 0)");
  Triangle triangle(triangle_description);
  SurfacePoint to_test(triangle, position);
  /*
  WHEN( "getEmission is called" ) {
    Vector3f direction;
    Vector3f emission = to_test.getEmission(toPosition, outDirection, true);
    THEN( "???" ) {
    }
  }
  WHEN( "getReflection is called" ) {
    Vector3f direction;
    Vector3f emission = to_test.getEmission(toPosition, outDirection, true);
    THEN( "???" ) {
    }
  }
  WHEN( "getNextDirection is called" ) {
    THEN( "???" ) {
    }
  }
  WHEN( "getHitId is called" ) {
    THEN( "???" ) {
    }
  }
  WHEN( "getPosition is called" ) {
    THEN( "???" ) {
    }
  }
  */
}

