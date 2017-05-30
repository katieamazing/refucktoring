#include "catch.h"
#include "spatial_index.h"
#include "vector3f.h"
#include "triangle.h"

using namespace hxa7241_minilight;
using namespace hxa7241_graphics;

SCENARIO( "spatial index is constructed like the smits-large scene", "[spatial_index]" ) {
  Vector3f eye_position(0.0, 0.650, -1.273);
  std::stringstream to_parse("(-20 0 -20) (-20 0 20) (20 0 -20)  (0.75 0.75 0.75) (0 0 0)\n"
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
  WHEN( "getIntersection hits a triangle" ) {
    Vector3f rayOrigin(0, 0.65, -1.273);
    Vector3f rayDirection(0.355581, -0.0295251, 0.934179);
    const Triangle* hitObject = 0;
    Vector3f hitPosition;
    to_test.getIntersection(rayOrigin, rayDirection, 0, hitObject, hitPosition);
    THEN( "hitObject is not zero" ) {
      REQUIRE( hitObject != 0 );
    }
    AND_THEN( "the first coordinate is approximately equal") {
      REQUIRE(hitPosition[0] == Approx(7.82817));
    }
    AND_THEN( "the second coordinate is approximately equal" ) {
      REQUIRE(hitPosition[1] == Approx(1.11022e-16));
    }
    AND_THEN( "the third coordinate is approximately equal" ) {
      REQUIRE(hitPosition[2] == Approx(19.2931));
    }
  }
  WHEN( "getIntersection hits a triangle" ) {
    Vector3f rayOrigin(0, 0.65, -1.273);
    Vector3f rayDirection(0.353279, -0.0293619, 0.935057);
    const Triangle* hitObject = 0;
    Vector3f hitPosition;
    to_test.getIntersection(rayOrigin, rayDirection, 0, hitObject, hitPosition);
    THEN( "hitObject is not zero" ) {
      REQUIRE( hitObject != 0 );
    }
    AND_THEN( "the first coordinate is approximately equal") {
      REQUIRE(hitPosition[0] == Approx(7.82073));
    }
    AND_THEN( "the second coordinate is approximately equal" ) {
      REQUIRE(hitPosition[1] == Approx(1.11022e-16));
    }
    AND_THEN( "the third coordinate is approximately equal" ) {
      REQUIRE(hitPosition[2] == Approx(19.4269));
    }
  }
  WHEN( "getIntersection hits a triangle" ) {
    Vector3f rayOrigin(0, 0.65, -1.273);
    Vector3f rayDirection(0.347371, -0.0291301, 0.937275);
    const Triangle* hitObject = 0;
    Vector3f hitPosition;
    to_test.getIntersection(rayOrigin, rayDirection, 0, hitObject, hitPosition);
    THEN( "hitObject is not zero" ) {
      REQUIRE( hitObject != 0 );
    }
    AND_THEN( "the first coordinate is approximately equal") {
      REQUIRE(hitPosition[0] == Approx(7.75111));
    }
    AND_THEN( "the second coordinate is approximately equal" ) {
      REQUIRE(hitPosition[1] == Approx(-1.11022e-16));
    }
    AND_THEN( "the third coordinate is approximately equal" ) {
      REQUIRE(hitPosition[2] == Approx(19.641));
    }
  }
  WHEN( "getIntersection hits a triangle" ) {
    Vector3f rayOrigin(0, 0.65, -1.273);
    Vector3f rayDirection(0.345175, -0.029966, 0.93806);
    const Triangle* hitObject = 0;
    Vector3f hitPosition;
    to_test.getIntersection(rayOrigin, rayDirection, 0, hitObject, hitPosition);
    THEN( "hitObject is not zero" ) {
      REQUIRE( hitObject != 0 );
    }
    AND_THEN( "the first coordinate is approximately equal") {
      REQUIRE(hitPosition[0] == Approx(7.48727));
    }
    AND_THEN( "the second coordinate is approximately equal" ) {
      REQUIRE(hitPosition[1] == Approx(0));
    }
    AND_THEN( "the third coordinate is approximately equal" ) {
      REQUIRE(hitPosition[2] == Approx(19.0747));
    }
  }
  WHEN( "getIntersection hits a triangle" ) {
    Vector3f rayOrigin(0, 0.65, -1.273);
    Vector3f rayDirection(0.34178, -0.0299228, 0.939304);
    const Triangle* hitObject = 0;
    Vector3f hitPosition;
    to_test.getIntersection(rayOrigin, rayDirection, 0, hitObject, hitPosition);
    THEN( "hitObject is not zero" ) {
      REQUIRE( hitObject != 0 );
    }
    AND_THEN( "the first coordinate is approximately equal") {
      REQUIRE(hitPosition[0] == Approx(7.42434));
    }
    AND_THEN( "the second coordinate is approximately equal" ) {
      REQUIRE(hitPosition[1] == Approx(1.11022e-16));
    }
    AND_THEN( "the third coordinate is approximately equal" ) {
      REQUIRE(hitPosition[2] == Approx(19.1311));
    }
  }
  WHEN( "getIntersection hits a triangle" ) {
    Vector3f rayOrigin(0, 0.65, -1.273);
    Vector3f rayDirection(0.338969, -0.029862, 0.940324);
    const Triangle* hitObject = 0;
    Vector3f hitPosition;
    to_test.getIntersection(rayOrigin, rayDirection, 0, hitObject, hitPosition);
    THEN( "hitObject is not zero" ) {
      REQUIRE( hitObject != 0 );
    }
    AND_THEN( "the first coordinate is approximately equal") {
      REQUIRE(hitPosition[0] == Approx(7.37826));
    }
    AND_THEN( "the second coordinate is approximately equal" ) {
      REQUIRE(hitPosition[1] == Approx(1.11022e-16));
    }
    AND_THEN( "the third coordinate is approximately equal" ) {
      REQUIRE(hitPosition[2] == Approx(19.1948));
    }
  }
  WHEN( "getIntersection hits a triangle" ) {
    Vector3f rayOrigin(0, 0.65, -1.273);
    Vector3f rayDirection(0.334946, -0.0300013, 0.941759);
    const Triangle* hitObject = 0;
    Vector3f hitPosition;
    to_test.getIntersection(rayOrigin, rayDirection, 0, hitObject, hitPosition);
    THEN( "hitObject is not zero" ) {
      REQUIRE( hitObject != 0 );
    }
    AND_THEN( "the first coordinate is approximately equal") {
      REQUIRE(hitPosition[0] == Approx(7.25685));
    }
    AND_THEN( "the second coordinate is approximately equal" ) {
      REQUIRE(hitPosition[1] == Approx(0));
    }
    AND_THEN( "the third coordinate is approximately equal" ) {
      REQUIRE(hitPosition[2] == Approx(19.1309));
    }
  }
  WHEN( "getIntersection hits a triangle" ) {
    Vector3f rayOrigin(0, 0.65, -1.273);
    Vector3f rayDirection(0.332778, -0.0295473, 0.942542);
    const Triangle* hitObject = 0;
    Vector3f hitPosition;
    to_test.getIntersection(rayOrigin, rayDirection, 0, hitObject, hitPosition);
    THEN( "hitObject is not zero" ) {
      REQUIRE( hitObject != 0 );
    }
    AND_THEN( "the first coordinate is approximately equal") {
      REQUIRE(hitPosition[0] == Approx(7.32065));
    }
    AND_THEN( "the second coordinate is approximately equal" ) {
      REQUIRE(hitPosition[1] == Approx(1.11022e-16));
    }
    AND_THEN( "the third coordinate is approximately equal" ) {
      REQUIRE(hitPosition[2] == Approx(19.4616));
    }
  }
  WHEN( "getIntersection hits a triangle" ) {
    Vector3f rayOrigin(0, 0.65, -1.273);
    Vector3f rayDirection(0.326619, -0.0288841, 0.944714);
    const Triangle* hitObject = 0;
    Vector3f hitPosition;
    to_test.getIntersection(rayOrigin, rayDirection, 0, hitObject, hitPosition);
    THEN( "hitObject is not zero" ) {
      REQUIRE( hitObject != 0 );
    }
    AND_THEN( "the first coordinate is approximately equal") {
      REQUIRE(hitPosition[0] == Approx(7.35017));
    }
    AND_THEN( "the second coordinate is approximately equal" ) {
      REQUIRE(hitPosition[1] == Approx(1.11022e-16));
    }
    AND_THEN( "the third coordinate is approximately equal" ) {
      REQUIRE(hitPosition[2] == Approx(19.9866));
    }
  }
  WHEN( "getIntersection hits a triangle" ) {
    Vector3f rayOrigin(0, 0.65, -1.273);
    Vector3f rayDirection(0.324204, -0.0290241, 0.945542);
    const Triangle* hitObject = 0;
    Vector3f hitPosition;
    to_test.getIntersection(rayOrigin, rayDirection, 0, hitObject, hitPosition);
    THEN( "hitObject is not zero" ) {
      REQUIRE( hitObject != 0 );
    }
    AND_THEN( "the first coordinate is approximately equal") {
      REQUIRE(hitPosition[0] == Approx(7.2606));
    }
    AND_THEN( "the second coordinate is approximately equal" ) {
      REQUIRE(hitPosition[1] == Approx(0));
    }
    AND_THEN( "the third coordinate is approximately equal" ) {
      REQUIRE(hitPosition[2] == Approx(19.9026));
    }
  }
  WHEN( "getIntersection hits a triangle" ) {
    Vector3f rayOrigin(0, 0.65, -1.273);
    Vector3f rayDirection(0.322567, -0.0295552, 0.946085);
    const Triangle* hitObject = 0;
    Vector3f hitPosition;
    to_test.getIntersection(rayOrigin, rayDirection, 0, hitObject, hitPosition);
    THEN( "hitObject is not zero" ) {
      REQUIRE( hitObject != 0 );
    }
    AND_THEN( "the first coordinate is approximately equal") {
      REQUIRE(hitPosition[0] == Approx(7.09411));
    }
    AND_THEN( "the second coordinate is approximately equal" ) {
      REQUIRE(hitPosition[1] == Approx(0));
    }
    AND_THEN( "the third coordinate is approximately equal" ) {
      REQUIRE(hitPosition[2] == Approx(19.534));
    }
  }
}
