#include "catch.h"
#include "ray_tracer.h"
#include "vector3f.h"
#include "scene.h"

using namespace hxa7241_minilight;

SCENARIO( "Ray tracing the scene from the minilight README", "[ray_tracer]" ) {
  std::istringstream scene_description("(3626 5572 5802) (0.1 0.09 0.07)\n"
				       "(0 0 0) (0 1 0) (1 1 0) (0.7 0.7 0.7) (0 0 0)");
  Vector3f eye_point(0.0, 0.75, -2.0);
  Scene scene(scene_description, eye_point);
  RayTracer to_test(scene);
  /*
    WHEN( "getRadiance is called" ) {
    }
  */
}

