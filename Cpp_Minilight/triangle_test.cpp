#include "catch.h"
#include "triangle.h"
#include "random.h"

using namespace hxa7241_minilight;

SCENARIO( "The triangle from the minimilight README", "[triangle]" ) {
  std::istringstream triangle_description("(0 0 0) (0 1 0) (1 1 0) (0.7 0.7 0.7) (0 0 0)");
  Triangle to_test(triangle_description);
  WHEN( "getBound is called" ) {
    real64 bound[6];
    to_test.getBound(bound);
    THEN( "bound[0] is approximately" ) {
      REQUIRE(bound[0] == Approx(-0.0009765625));
    }
    AND_THEN( "bound[1] is approximately" ) {
      REQUIRE(bound[1] == Approx(-0.0009765625));
    }
    AND_THEN( "bound[2] is approximately" ) {
      REQUIRE(bound[2] == Approx(-0.0009765625));
    }
    AND_THEN( "bound[3] is approximately" ) {
      REQUIRE(bound[3] == Approx(1.0009765625));
    }
    AND_THEN( "bound[4] is approximately" ) {
      REQUIRE(bound[4] == Approx(1.0009765625));
    }
    AND_THEN( "bound[5] is approximately" ) {
      REQUIRE(bound[5] == Approx(0.0009765625));
    }
  }
  WHEN( "getNormal is called" ) {
    Vector3f normal = to_test.getNormal();
    THEN( "normal[0] is approximately" ) {
      REQUIRE(normal[0] == Approx(0.0));
    }
    AND_THEN( "normal[1] is approximately" ) {
      REQUIRE(normal[1] == Approx(0.0));
    }
    AND_THEN( "normal[2] is approximately" ) {
      REQUIRE(normal[2] == Approx(-1.0));
    }
  }
  WHEN( "getTangent is called" ) {
    Vector3f tangent = to_test.getTangent();
    THEN( "tangent[0] is approximately" ) {
      REQUIRE(tangent[0] == Approx(0.0));
    }
    AND_THEN( "tangent[1] is approximately" ) {
      REQUIRE(tangent[1] == Approx(1.0));
    }
    AND_THEN( "tangent[2] is approximately" ) {
      REQUIRE(tangent[2] == Approx(0.0));
    }
  }
  WHEN( "getArea is called" ) {
    real64 area = to_test.getArea();
    THEN( "area is approximately" ) {
      REQUIRE(area == Approx(0.5));
    }
  }
  WHEN( "getReflectivity is called" ) {
    Vector3f reflectivity = to_test.getReflectivity();
    THEN( "reflectivity[0] is approximately" ) {
      REQUIRE(reflectivity[0] == Approx(0.7));
    }
    AND_THEN( "reflectivity[1] is approximately" ) {
      REQUIRE(reflectivity[1] == Approx(0.7));
    }
    AND_THEN( "reflectivity[2] is approximately" ) {
      REQUIRE(reflectivity[2] == Approx(0.7));
    }
  }
  WHEN( "getEmitivity is called" ) {
    Vector3f emitivity = to_test.getEmitivity();
    THEN( "emitivity[0] is approximately" ) {
      REQUIRE(emitivity[0] == Approx(0.0));
    }
    AND_THEN( "emitivity[1] is approximately" ) {
      REQUIRE(emitivity[1] == Approx(0.0));
    }
    AND_THEN( "emitivity[2] is approximately" ) {
      REQUIRE(emitivity[2] == Approx(0.0));
    }
  }
  WHEN( "getSamplePoint is called" ) {
    Random rng;
    Vector3f sample = to_test.getSamplePoint(rng);
    THEN( "sample[0] is approximately" ) {
      REQUIRE(sample[0] == Approx(0.606580777));
    }
    AND_THEN( "sample[1] is approximately" ) {
      REQUIRE(sample[1] == Approx(0.9582923164));
    }
    AND_THEN( "sample[2] is approximately" ) {
      REQUIRE(sample[2] == Approx(0.0));
    }
  }
  /*
    TODO getIntersection
  */
}
