#include "catch.h"
#include "triangle.h"

using namespace hxa7241_minilight;

SCENARIO( "The triangle from the minimilight README", "[triangle]" ) {
  std::istringstream triangle_description("(0 0 0) (0 1 0) (1 1 0) (0.7 0.7 0.7) (0 0 0)");
  Triangle to_test(triangle_description);
  WHEN( "getBound is called" ) {
    real64 bound[6];
    to_test.getBound(bound);
    THEN( "bound[0] is approximately -0.0009765625" ) {
      REQUIRE(bound[0] == Approx(-0.0009765625));
    }
    AND_THEN( "bound[1] is approximately " ) {
      REQUIRE(bound[1] == Approx(-0.0009765625));
    }
    AND_THEN( "bound[2] is approximately " ) {
      REQUIRE(bound[2] == Approx(-0.0009765625));
    }
    AND_THEN( "bound[3] is approximately " ) {
      REQUIRE(bound[3] == Approx(1.0009765625));
    }
    AND_THEN( "bound[4] is approximately " ) {
      REQUIRE(bound[4] == Approx(1.0009765625));
    }
    AND_THEN( "bound[5] is approximately " ) {
      REQUIRE(bound[5] == Approx(0.0009765625));
    }
  }
  /*
getIntersection
getSamplePoint
getNormal
getTangent
getArea
getReflectivity
getEmitivity
  */
}
