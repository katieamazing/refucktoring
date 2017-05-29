#include "catch.h"
#include "scene.h"
#include "vector3f.h"
#include "random.h"

using namespace hxa7241_minilight;
using namespace hxa7241_graphics;

SCENARIO( "The scene from the minilight README", "[scene]" ) {
  std::istringstream scene_description("(3626 5572 5802) (0.1 0.09 0.07)\n"
				       "(0 0 0) (0 1 0) (1 1 0) (0.7 0.7 0.7) (0 0 0)");
  Vector3f eye_point(0.0, 0.75, -2.0);
  Scene to_test(scene_description, eye_point);
  /*
  WHEN( "getIntersection is called" ) {
    Vector3f rayOrigin(0.0, 0.0, 0.0);
    Vector3f rayDirection(0.0, 0.0, 1.0);
    
    to_test.getIntersection(rayOrigin, rayDirection, lastHit, &hitObject, hitPosition)
    THEN( "Something" ) {

    }
  }
  */
  /*
  WHEN( "getEmitter is called" ) {
    Random random;
    Vector3f which_position;
    Triangle which_triangle;
    to_test.getEmitter(random, which_position, &which_triangle);
    THEN( "position and triangle are as expected" ) {
    }
  }
  */
  WHEN( "getEmittersCount is called") {
    int32 count = to_test.getEmittersCount();
    THEN( "count equals the expected value" ) {
      REQUIRE( count == 0 );
    }
  }
}
