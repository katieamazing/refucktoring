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
  real64 c = random.getReal64();
  real64 d = random.getReal64();
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
  WHEN( "testing that zero is the additive identity" ) {
    Vector3f zero_plus_x = Vector3f::ZERO() + x;
    Vector3f x_plus_zero = x + Vector3f::ZERO();
    THEN( "the first coordinate is approximately equal" ) {
      REQUIRE(zero_plus_x[0] == Approx(x_plus_zero[0]));
    }
    AND_THEN( "the second coordinate is approximately equal" ) {
      REQUIRE(zero_plus_x[1] == Approx(x_plus_zero[1]));
    }
    AND_THEN( "the third coordinate is approximately equal" ) {
      REQUIRE(zero_plus_x[2] == Approx(x_plus_zero[2]));
    }
  }
  WHEN( "testing that subtraction works" ) {
    Vector3f negative_x = Vector3f::ZERO() - x;
    Vector3f negative_x_plus_x = negative_x + x;
    Vector3f x_plus_negative_x = x + negative_x;
    THEN( "the first coordinate is approximately equal" ) {
      REQUIRE(negative_x_plus_x[0] == Approx(x_plus_negative_x[0]));
    }
    AND_THEN( "the second coordinate is approximately equal" ) {
      REQUIRE(negative_x_plus_x[1] == Approx(x_plus_negative_x[2]));
    }
    AND_THEN( "the third coordinate is approximately equal" ) {
      REQUIRE(negative_x_plus_x[2] == Approx(x_plus_negative_x[2]));
    }
  }
  WHEN( "multiplying by a scalar zero" ) {
    Vector3f x_times_zero = x * 0;
    THEN( "the first coordinate is approximately equal" ) {
      REQUIRE(x_times_zero[0] == Approx(Vector3f::ZERO()[0]));
    }
    AND_THEN( "the second coordinate is approximately equal" ) {
      REQUIRE(x_times_zero[1] == Approx(Vector3f::ZERO()[2]));
    }
    AND_THEN( "the third coordinate is approximately equal" ) {
      REQUIRE(x_times_zero[2] == Approx(Vector3f::ZERO()[2]));
    }
  }
  WHEN( "multiplying by a scalar one" ) {
    Vector3f x_times_one = x * 1;
    THEN( "the first coordinate is approximately equal" ) {
      REQUIRE(x_times_one[0] == Approx(x[0]));
    }
    AND_THEN( "the second coordinate is approximately equal" ) {
      REQUIRE(x_times_one[1] == Approx(x[1]));
    }
    AND_THEN( "the third coordinate is approximately equal" ) {
      REQUIRE(x_times_one[2] == Approx(x[2]));
    }
  }
  WHEN( "multiplying by two scalars" ) {
    Vector3f x_times_cd = x * (c * d);
    Vector3f x_times_c_times_d = (x * c) * d;
    THEN( "the first coordinate is approximately equal" ) {
      REQUIRE(x_times_cd[0] == Approx(x_times_c_times_d[0]));
    }
    AND_THEN( "the second coordinate is approximately equal" ) {
      REQUIRE(x_times_cd[1] == Approx(x_times_c_times_d[1]));
    }
    AND_THEN( "the third coordinate is approximately equal" ) {
      REQUIRE(x_times_cd[2] == Approx(x_times_c_times_d[2]));
    }
  }
  WHEN( "testing distribution of scalar multiplication over vector addition" ) {
    Vector3f x_plus_y_times_c = (x + y) * c;
    Vector3f x_times_c_plus_y_times_c = x * c + y * c;
    THEN( "the first coordinate is approximately equal" ) {
      REQUIRE(x_plus_y_times_c[0] == Approx(x_times_c_plus_y_times_c[0]));
    }
    AND_THEN( "the second coordinate is approximately equal" ) {
      REQUIRE(x_plus_y_times_c[1] == Approx(x_times_c_plus_y_times_c[1]));
    }
    AND_THEN( "the third coordinate is approximately equal" ) {
      REQUIRE(x_plus_y_times_c[2] == Approx(x_times_c_plus_y_times_c[2]));
    }
  }
  WHEN( "testing commutativity of dot product" ) {
    real64 x_dot_y = x.dot(y);
    real64 y_dot_x = y.dot(x);
    THEN( "they are approximately equal" ) {
      REQUIRE(x_dot_y == Approx(y_dot_x));
    }
  }
  WHEN( "testing that scalar multiplication commutes with dot product" ) {
    real64 x_times_c_dot_y = (x * c).dot(y);
    real64 x_dot_y_times_c = x.dot(y) * c;
    THEN( "they are approximately equal" ) {
      REQUIRE(x_times_c_dot_y == Approx(x_dot_y_times_c));
    }
  }
  WHEN( "testing dot product distributes over vector addition" ) {
    real64 x_plus_y_dot_z = (x + y).dot(z);
    real64 x_dot_z_plus_y_dot_z = x.dot(z) + y.dot(z);
    THEN( "they are approximately equal" ) {
      REQUIRE(x_plus_y_dot_z == Approx(x_dot_z_plus_y_dot_z));
    }
  }
  WHEN( "testing x dot x is greater than zero" ) {
    real64 x_dot_x = x.dot(x);
    THEN( "greater than zero" ) {
      REQUIRE(x_dot_x > 0.0);
    }
  }
  WHEN( "testing zero dot zero is equal to zero" ) {
    real64 zero_dot_zero = Vector3f::ZERO().dot(Vector3f::ZERO());
    THEN( "equals zero" ) {
      REQUIRE(zero_dot_zero == 0.0);
    }
  }
}

SCENARIO( "axioms of vector spaces, unitized", "[vector3f]" ) {
  Random random;
  Vector3f x = Vector3f(random.getReal64(), random.getReal64(), random.getReal64()).unitize();
  Vector3f y = Vector3f(random.getReal64(), random.getReal64(), random.getReal64()).unitize();
  Vector3f z = Vector3f(random.getReal64(), random.getReal64(), random.getReal64()).unitize();
  real64 c = random.getReal64();
  real64 d = random.getReal64();
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
  WHEN( "testing that zero is the additive identity" ) {
    Vector3f zero_plus_x = Vector3f::ZERO() + x;
    Vector3f x_plus_zero = x + Vector3f::ZERO();
    THEN( "the first coordinate is approximately equal" ) {
      REQUIRE(zero_plus_x[0] == Approx(x_plus_zero[0]));
    }
    AND_THEN( "the second coordinate is approximately equal" ) {
      REQUIRE(zero_plus_x[1] == Approx(x_plus_zero[1]));
    }
    AND_THEN( "the third coordinate is approximately equal" ) {
      REQUIRE(zero_plus_x[2] == Approx(x_plus_zero[2]));
    }
  }
  WHEN( "testing that subtraction works" ) {
    Vector3f negative_x = Vector3f::ZERO() - x;
    Vector3f negative_x_plus_x = negative_x + x;
    Vector3f x_plus_negative_x = x + negative_x;
    THEN( "the first coordinate is approximately equal" ) {
      REQUIRE(negative_x_plus_x[0] == Approx(x_plus_negative_x[0]));
    }
    AND_THEN( "the second coordinate is approximately equal" ) {
      REQUIRE(negative_x_plus_x[1] == Approx(x_plus_negative_x[2]));
    }
    AND_THEN( "the third coordinate is approximately equal" ) {
      REQUIRE(negative_x_plus_x[2] == Approx(x_plus_negative_x[2]));
    }
  }
  WHEN( "multiplying by a scalar zero" ) {
    Vector3f x_times_zero = x * 0;
    THEN( "the first coordinate is approximately equal" ) {
      REQUIRE(x_times_zero[0] == Approx(Vector3f::ZERO()[0]));
    }
    AND_THEN( "the second coordinate is approximately equal" ) {
      REQUIRE(x_times_zero[1] == Approx(Vector3f::ZERO()[2]));
    }
    AND_THEN( "the third coordinate is approximately equal" ) {
      REQUIRE(x_times_zero[2] == Approx(Vector3f::ZERO()[2]));
    }
  }
  WHEN( "multiplying by a scalar one" ) {
    Vector3f x_times_one = x * 1;
    THEN( "the first coordinate is approximately equal" ) {
      REQUIRE(x_times_one[0] == Approx(x[0]));
    }
    AND_THEN( "the second coordinate is approximately equal" ) {
      REQUIRE(x_times_one[1] == Approx(x[1]));
    }
    AND_THEN( "the third coordinate is approximately equal" ) {
      REQUIRE(x_times_one[2] == Approx(x[2]));
    }
  }
  WHEN( "multiplying by two scalars" ) {
    Vector3f x_times_cd = x * (c * d);
    Vector3f x_times_c_times_d = (x * c) * d;
    THEN( "the first coordinate is approximately equal" ) {
      REQUIRE(x_times_cd[0] == Approx(x_times_c_times_d[0]));
    }
    AND_THEN( "the second coordinate is approximately equal" ) {
      REQUIRE(x_times_cd[1] == Approx(x_times_c_times_d[1]));
    }
    AND_THEN( "the third coordinate is approximately equal" ) {
      REQUIRE(x_times_cd[2] == Approx(x_times_c_times_d[2]));
    }
  }
  WHEN( "testing distribution of scalar multiplication over vector addition" ) {
    Vector3f x_plus_y_times_c = (x + y) * c;
    Vector3f x_times_c_plus_y_times_c = x * c + y * c;
    THEN( "the first coordinate is approximately equal" ) {
      REQUIRE(x_plus_y_times_c[0] == Approx(x_times_c_plus_y_times_c[0]));
    }
    AND_THEN( "the second coordinate is approximately equal" ) {
      REQUIRE(x_plus_y_times_c[1] == Approx(x_times_c_plus_y_times_c[1]));
    }
    AND_THEN( "the third coordinate is approximately equal" ) {
      REQUIRE(x_plus_y_times_c[2] == Approx(x_times_c_plus_y_times_c[2]));
    }
  }
  WHEN( "testing commutativity of dot product" ) {
    real64 x_dot_y = x.dot(y);
    real64 y_dot_x = y.dot(x);
    THEN( "they are approximately equal" ) {
      REQUIRE(x_dot_y == Approx(y_dot_x));
    }
  }
  WHEN( "testing that scalar multiplication commutes with dot product" ) {
    real64 x_times_c_dot_y = (x * c).dot(y);
    real64 x_dot_y_times_c = x.dot(y) * c;
    THEN( "they are approximately equal" ) {
      REQUIRE(x_times_c_dot_y == Approx(x_dot_y_times_c));
    }
  }
  WHEN( "testing dot product distributes over vector addition" ) {
    real64 x_plus_y_dot_z = (x + y).dot(z);
    real64 x_dot_z_plus_y_dot_z = x.dot(z) + y.dot(z);
    THEN( "they are approximately equal" ) {
      REQUIRE(x_plus_y_dot_z == Approx(x_dot_z_plus_y_dot_z));
    }
  }
  WHEN( "testing x dot x is approximately one" ) {
    real64 x_dot_x = x.dot(x);
    THEN( "equals approximately one" ) {
      REQUIRE(x_dot_x == Approx(1.0));
    }
  }
}
