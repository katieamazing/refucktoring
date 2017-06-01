#include "catch.h"
#include "image.h"

using namespace hxa7241_minilight;

SCENARIO( "The image from the minilight README" ) {
  std::istringstream image_description("200 150");
  Image to_test(image_description);
  /*
addToPixel
getWidth
getHeight
getFormatted
  */
}

