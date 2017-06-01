#include "catch.h"
#include "camera.h"

using namespace hxa7241_minilight;

SCENARIO( "The camera from the minilight README", "[camera]") {
  std::istringstream camera_description("(0 0.75 -2) (0 0 1) 45");
  Camera to_test(camera_description);
  WHEN( "The eye point is queried" ) {
    Vector3f eye_point = to_test.getEyePoint();
    THEN( "The coordinates are approximately equal to the specified view position" ) {
      REQUIRE(eye_point[0] == Approx(0.0));
      REQUIRE(eye_point[1] == Approx(0.75));
      REQUIRE(eye_point[2] == Approx(-2.0));
    }
  }
  /*
  WHEN( "Something" ) {
    Scene scene;
    Random random;
    Image image;
    to_test.getFrame(scene, random, image);
    THEN( "Something" ) {
      // REQUIRE() something about the image?
    }
  }
  */
}

