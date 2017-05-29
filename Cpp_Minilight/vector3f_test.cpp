#include "catch.h"
#include "vector3f.h"
#include "random.h"

using namespace hxa7241_graphics;
using namespace hxa7241_general;

SCENARIO( "axioms of vector spaces", "[vector3f]" ) {
  Random random;
  Vector3f x(random.getReal64(), random.getReal64(), random.getReal64());
  Vector3f y(random.getReal64(), random.getReal64(), random.getReal64());
  Vector3f z(random.getReal64(), random.getReal64(), random.getReal64());
  WHEN( "commutativity is tested" ) {
    Vector3f x_plus_y = x + y;
    Vector3f y_plus_x = y + x;
    THEN( "the first coordinate is approximately equal" ) {
      REQUIRE(x_plus_y[0] == Approx(y_plus_x[0]));
    }
    AND_THEN( "the second coordinate is approximately equal" ) {
      REQUIRE(x_plus_y[1] == Approx(y_plus_x[1]));
    }
    AND_THEN( "the third coordinate is approximately equal" ) {
      REQUIRE(x_plus_y[2] == Approx(y_plus_x[2]));
    }
  }
  WHEN( "associativity is tested" ) {
    Vector3f x_plus_y = x + y;
    Vector3f x_plus_y__plus_z = x_plus_y + z;
    Vector3f y_plus_z = y + z;
    Vector3f x_plus__y_plus_z = x + y_plus_z;
    THEN( "the first coordinate is approximately equal" ) {
      REQUIRE(x_plus_y__plus_z[0] == Approx(x_plus__y_plus_z[0]));
    }
    AND_THEN( "the second coordinate is approximately equal" ) {
      REQUIRE(x_plus_y__plus_z[1] == Approx(x_plus__y_plus_z[1]));
    }
    AND_THEN( "the third coordinate is approximately equal" ) {
      REQUIRE(x_plus_y__plus_z[2] == Approx(x_plus__y_plus_z[2]));
    }
  }
  /*
TODO:

0 + x = x + 0 = x
(-1) + x = x + (-x) = 0
0 * x = 0
1 * x = 1
(cd)*x = c * (d * x)
c * (x + y) = c * x + c * y
(c * d) * x = c * x + d * x

x . y = y . x
a*x . y = a * (x . y)
(x + y) . z = (x . z) + (y . z)
x . x >= 0
x . x = 0 iff x = 0
  */
}
