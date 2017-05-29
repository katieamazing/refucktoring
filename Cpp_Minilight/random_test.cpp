#include "catch.h"
#include "random.h"

using namespace hxa7241_general;

SCENARIO( "The initial integers from the RNG are as usual", "[random]") {
  Random to_test;
  WHEN( "The first three ints from the RNG are generated" ) {
    THEN( "They are equal to the expected values" ) {
      REQUIRE( to_test.getInt32u() == 3952563604 );
      REQUIRE( to_test.getInt32u() == 1192989748 );
      REQUIRE( to_test.getInt32u() == 2423800670 );
    }
  }
  WHEN( "The first three floats from the RNG are generated" ) {
    THEN( "They are approximately equal to the expected values" ) {
      REQUIRE( to_test.getReal64() == Approx(0.4202779282) );
      REQUIRE( to_test.getReal64() == Approx(0.0643350702) );
      REQUIRE( to_test.getReal64() == Approx(0.6835013845) );
    }
  }
}
