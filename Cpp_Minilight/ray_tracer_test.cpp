#include "catch.h"
#include "ray_tracer.h"
#include "vector3f.h"
#include "scene.h"
#include "random.h"

using namespace hxa7241_minilight;

SCENARIO( "We are ray tracing the smits large scene", "[ray_tracer][!mayfail]" ) {
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
    Vector3f eye_point(0.0, 0.64, -1.273);
    Scene scene(to_parse, eye_point);
    RayTracer to_test(scene);
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0295251, -0.0295251, 0.934179);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.03651e-06));
      // REQUIRE(radiance[1] == Approx(2.03651e-06));
      // REQUIRE(radiance[2] == Approx(-20.0));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0293619, -0.0293619, 0.935057);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(0.928302));
      // REQUIRE(radiance[1] == Approx(0.928302));
      // REQUIRE(radiance[2] == Approx(0.928302));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0291301, -0.0291301, 0.937275);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(1.91789e-06));
      // REQUIRE(radiance[1] == Approx(1.91789e-06));
      // REQUIRE(radiance[2] == Approx(1.91789e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.029966, -0.029966, 0.93806);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.18295e-06));
      // REQUIRE(radiance[1] == Approx(2.18295e-06));
      // REQUIRE(radiance[2] == Approx(2.18295e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0299228, -0.0299228, 0.939304);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.14178e-06));
      // REQUIRE(radiance[1] == Approx(2.14178e-06));
      // REQUIRE(radiance[2] == Approx(2.14178e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.029862, -0.029862, 0.940324);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.14298e-06));
      // REQUIRE(radiance[1] == Approx(2.14298e-06));
      // REQUIRE(radiance[2] == Approx(2.14298e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0300013, -0.0300013, 0.941759);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(0.971654));
      // REQUIRE(radiance[1] == Approx(0.971654));
      // REQUIRE(radiance[2] == Approx(0.971654));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0295473, -0.0295473, 0.942542);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(0.955673));
      // REQUIRE(radiance[1] == Approx(0.955673));
      // REQUIRE(radiance[2] == Approx(0.955673));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0288841, -0.0288841, 0.944714);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(0.85465));
      // REQUIRE(radiance[1] == Approx(0.85465));
      // REQUIRE(radiance[2] == Approx(0.85465));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0290241, -0.0290241, 0.945542);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(0.803166));
      // REQUIRE(radiance[1] == Approx(0.803166));
      // REQUIRE(radiance[2] == Approx(0.803166));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0295552, -0.0295552, 0.946085);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.04236e-06));
      // REQUIRE(radiance[1] == Approx(2.04236e-06));
      // REQUIRE(radiance[2] == Approx(2.04236e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0305018, -0.0305018, 0.94724);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(1.01496));
      // REQUIRE(radiance[1] == Approx(1.01496));
      // REQUIRE(radiance[2] == Approx(1.01496));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0300027, -0.0300027, 0.94772);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(0.891398));
      // REQUIRE(radiance[1] == Approx(0.891398));
      // REQUIRE(radiance[2] == Approx(0.891398));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0293804, -0.0293804, 0.948707);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(0.912798));
      // REQUIRE(radiance[1] == Approx(0.912798));
      // REQUIRE(radiance[2] == Approx(0.912798));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0299372, -0.0299372, 0.948824);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(0.877391));
      // REQUIRE(radiance[1] == Approx(0.877391));
      // REQUIRE(radiance[2] == Approx(0.877391));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.029307, -0.029307, 0.95017);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(1.96896e-06));
      // REQUIRE(radiance[1] == Approx(1.96896e-06));
      // REQUIRE(radiance[2] == Approx(1.96896e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0302286, -0.0302286, 0.950263);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.23539e-06));
      // REQUIRE(radiance[1] == Approx(2.23539e-06));
      // REQUIRE(radiance[2] == Approx(2.23539e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0295387, -0.0295387, 0.950968);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(0.830631));
      // REQUIRE(radiance[1] == Approx(0.830631));
      // REQUIRE(radiance[2] == Approx(0.830631));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0291695, -0.0291695, 0.95165);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(1.94164e-06));
      // REQUIRE(radiance[1] == Approx(1.94164e-06));
      // REQUIRE(radiance[2] == Approx(1.94164e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0298867, -0.0298867, 0.952417);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(0.940356));
      // REQUIRE(radiance[1] == Approx(0.940356));
      // REQUIRE(radiance[2] == Approx(0.940356));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0305484, -0.0305484, 0.953145);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(1.0376));
      // REQUIRE(radiance[1] == Approx(1.0376));
      // REQUIRE(radiance[2] == Approx(1.0376));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0302116, -0.0302116, 0.953878);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(0.90854));
      // REQUIRE(radiance[1] == Approx(0.90854));
      // REQUIRE(radiance[2] == Approx(0.90854));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0301223, -0.0301223, 0.954815);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(0.966653));
      // REQUIRE(radiance[1] == Approx(0.966653));
      // REQUIRE(radiance[2] == Approx(0.966653));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.030181, -0.030181, 0.956206);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(0.931939));
      // REQUIRE(radiance[1] == Approx(0.931939));
      // REQUIRE(radiance[2] == Approx(0.931939));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0304329, -0.0304329, 0.956752);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(0.968872));
      // REQUIRE(radiance[1] == Approx(0.968872));
      // REQUIRE(radiance[2] == Approx(0.968872));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0303032, -0.0303032, 0.958131);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(0.940528));
      // REQUIRE(radiance[1] == Approx(0.940528));
      // REQUIRE(radiance[2] == Approx(0.940528));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0299192, -0.0299192, 0.958922);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.16064e-06));
      // REQUIRE(radiance[1] == Approx(2.16064e-06));
      // REQUIRE(radiance[2] == Approx(2.16064e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0307309, -0.0307309, 0.959458);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(1.01624));
      // REQUIRE(radiance[1] == Approx(1.01624));
      // REQUIRE(radiance[2] == Approx(1.01624));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0299322, -0.0299322, 0.960018);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.15978e-06));
      // REQUIRE(radiance[1] == Approx(2.15978e-06));
      // REQUIRE(radiance[2] == Approx(2.15978e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0301096, -0.0301096, 0.960659);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.2092e-06));
      // REQUIRE(radiance[1] == Approx(2.2092e-06));
      // REQUIRE(radiance[2] == Approx(2.2092e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0304066, -0.0304066, 0.961159);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.31113e-06));
      // REQUIRE(radiance[1] == Approx(2.31113e-06));
      // REQUIRE(radiance[2] == Approx(2.31113e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0296481, -0.0296481, 0.962422);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(0.940625));
      // REQUIRE(radiance[1] == Approx(0.940625));
      // REQUIRE(radiance[2] == Approx(0.940625));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0298382, -0.0298382, 0.963513);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(0.87262));
      // REQUIRE(radiance[1] == Approx(0.87262));
      // REQUIRE(radiance[2] == Approx(0.87262));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0306652, -0.0306652, 0.964409);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.4228e-06));
      // REQUIRE(radiance[1] == Approx(2.4228e-06));
      // REQUIRE(radiance[2] == Approx(2.4228e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0296077, -0.0296077, 0.964775);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.07586e-06));
      // REQUIRE(radiance[1] == Approx(2.07586e-06));
      // REQUIRE(radiance[2] == Approx(2.07586e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0295913, -0.0295913, 0.965381);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.07672e-06));
      // REQUIRE(radiance[1] == Approx(2.07672e-06));
      // REQUIRE(radiance[2] == Approx(2.07672e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.03039, -0.03039, 0.967067);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.31441e-06));
      // REQUIRE(radiance[1] == Approx(2.31441e-06));
      // REQUIRE(radiance[2] == Approx(2.31441e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0297646, -0.0297646, 0.96762);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(0.962276));
      // REQUIRE(radiance[1] == Approx(0.962276));
      // REQUIRE(radiance[2] == Approx(0.962276));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.030943, -0.030943, 0.968819);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.48428e-06));
      // REQUIRE(radiance[1] == Approx(2.48428e-06));
      // REQUIRE(radiance[2] == Approx(2.48428e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0300603, -0.0300603, 0.969428);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.23585e-06));
      // REQUIRE(radiance[1] == Approx(2.23585e-06));
      // REQUIRE(radiance[2] == Approx(2.23585e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0308798, -0.0308798, 0.970957);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(0.987196));
      // REQUIRE(radiance[1] == Approx(0.987196));
      // REQUIRE(radiance[2] == Approx(0.987196));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0305964, -0.0305964, 0.971095);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.39303e-06));
      // REQUIRE(radiance[1] == Approx(2.39303e-06));
      // REQUIRE(radiance[2] == Approx(2.39303e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0303061, -0.0303061, 0.971646);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(0.999624));
      // REQUIRE(radiance[1] == Approx(0.999624));
      // REQUIRE(radiance[2] == Approx(0.999624));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0302221, -0.0302221, 0.973313);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.25544e-06));
      // REQUIRE(radiance[1] == Approx(2.25544e-06));
      // REQUIRE(radiance[2] == Approx(2.25544e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0300877, -0.0300877, 0.975701);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(0.975994));
      // REQUIRE(radiance[1] == Approx(0.975994));
      // REQUIRE(radiance[2] == Approx(0.975994));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0304363, -0.0304363, 0.975939);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.33974e-06));
      // REQUIRE(radiance[1] == Approx(2.33974e-06));
      // REQUIRE(radiance[2] == Approx(2.33974e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0302518, -0.0302518, 0.976818);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.25994e-06));
      // REQUIRE(radiance[1] == Approx(2.25994e-06));
      // REQUIRE(radiance[2] == Approx(2.25994e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0309035, -0.0309035, 0.977202);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(0.997834));
      // REQUIRE(radiance[1] == Approx(0.997834));
      // REQUIRE(radiance[2] == Approx(0.997834));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0304964, -0.0304964, 0.977505);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.37314e-06));
      // REQUIRE(radiance[1] == Approx(2.37314e-06));
      // REQUIRE(radiance[2] == Approx(2.37314e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0306756, -0.0306756, 0.977973);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(0.987929));
      // REQUIRE(radiance[1] == Approx(0.987929));
      // REQUIRE(radiance[2] == Approx(0.987929));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0313115, -0.0313115, 0.978538);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.6434e-06));
      // REQUIRE(radiance[1] == Approx(2.6434e-06));
      // REQUIRE(radiance[2] == Approx(2.6434e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0300057, -0.0300057, 0.97895);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.20685e-06));
      // REQUIRE(radiance[1] == Approx(2.20685e-06));
      // REQUIRE(radiance[2] == Approx(2.20685e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0299922, -0.0299922, 0.979777);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(0.999488));
      // REQUIRE(radiance[1] == Approx(0.999488));
      // REQUIRE(radiance[2] == Approx(0.999488));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0309644, -0.0309644, 0.979951);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.49192e-06));
      // REQUIRE(radiance[1] == Approx(2.49192e-06));
      // REQUIRE(radiance[2] == Approx(2.49192e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0307781, -0.0307781, 0.980316);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.45108e-06));
      // REQUIRE(radiance[1] == Approx(2.45108e-06));
      // REQUIRE(radiance[2] == Approx(2.45108e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.031498, -0.031498, 0.98189);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(1.18412));
      // REQUIRE(radiance[1] == Approx(1.18412));
      // REQUIRE(radiance[2] == Approx(1.18412));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0308177, -0.0308177, 0.982773);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.46799e-06));
      // REQUIRE(radiance[1] == Approx(2.46799e-06));
      // REQUIRE(radiance[2] == Approx(2.46799e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0311255, -0.0311255, 0.983357);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.58368e-06));
      // REQUIRE(radiance[1] == Approx(2.58368e-06));
      // REQUIRE(radiance[2] == Approx(2.58368e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0312976, -0.0312976, 0.984121);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.662e-06));
      // REQUIRE(radiance[1] == Approx(2.662e-06));
      // REQUIRE(radiance[2] == Approx(2.662e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0311227, -0.0311227, 0.984499);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.57847e-06));
      // REQUIRE(radiance[1] == Approx(2.57847e-06));
      // REQUIRE(radiance[2] == Approx(2.57847e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0313195, -0.0313195, 0.984889);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.62165e-06));
      // REQUIRE(radiance[1] == Approx(2.62165e-06));
      // REQUIRE(radiance[2] == Approx(2.62165e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0317166, -0.0317166, 0.985434);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.78023e-06));
      // REQUIRE(radiance[1] == Approx(2.78023e-06));
      // REQUIRE(radiance[2] == Approx(2.78023e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0314488, -0.0314488, 0.985557);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.68231e-06));
      // REQUIRE(radiance[1] == Approx(2.68231e-06));
      // REQUIRE(radiance[2] == Approx(2.68231e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0316343, -0.0316343, 0.985968);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.73054e-06));
      // REQUIRE(radiance[1] == Approx(2.73054e-06));
      // REQUIRE(radiance[2] == Approx(2.73054e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0312263, -0.0312263, 0.987719);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.61783e-06));
      // REQUIRE(radiance[1] == Approx(2.61783e-06));
      // REQUIRE(radiance[2] == Approx(2.61783e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0309283, -0.0309283, 0.988428);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(1.04507));
      // REQUIRE(radiance[1] == Approx(1.04507));
      // REQUIRE(radiance[2] == Approx(1.04507));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0313329, -0.0313329, 0.988656);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.68124e-06));
      // REQUIRE(radiance[1] == Approx(2.68124e-06));
      // REQUIRE(radiance[2] == Approx(2.68124e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0306959, -0.0306959, 0.988929);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.43829e-06));
      // REQUIRE(radiance[1] == Approx(2.43829e-06));
      // REQUIRE(radiance[2] == Approx(2.43829e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0302514, -0.0302514, 0.989783);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(1.01612));
      // REQUIRE(radiance[1] == Approx(1.01612));
      // REQUIRE(radiance[2] == Approx(1.01612));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.03121, -0.03121, 0.990505);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(1.05944));
      // REQUIRE(radiance[1] == Approx(1.05944));
      // REQUIRE(radiance[2] == Approx(1.05944));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0309448, -0.0309448, 0.990629);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(1.13749));
      // REQUIRE(radiance[1] == Approx(1.13749));
      // REQUIRE(radiance[2] == Approx(1.13749));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0310818, -0.0310818, 0.990995);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(1.00615));
      // REQUIRE(radiance[1] == Approx(1.00615));
      // REQUIRE(radiance[2] == Approx(1.00615));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0312506, -0.0312506, 0.991504);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.62145e-06));
      // REQUIRE(radiance[1] == Approx(2.62145e-06));
      // REQUIRE(radiance[2] == Approx(2.62145e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.03167, -0.03167, 0.991739);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(1.17018));
      // REQUIRE(radiance[1] == Approx(1.17018));
      // REQUIRE(radiance[2] == Approx(1.17018));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0304148, -0.0304148, 0.992002);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.33752e-06));
      // REQUIRE(radiance[1] == Approx(2.33752e-06));
      // REQUIRE(radiance[2] == Approx(2.33752e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0310563, -0.0310563, 0.992546);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.57759e-06));
      // REQUIRE(radiance[1] == Approx(2.57759e-06));
      // REQUIRE(radiance[2] == Approx(2.57759e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0308879, -0.0308879, 0.99284);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.48244e-06));
      // REQUIRE(radiance[1] == Approx(2.48244e-06));
      // REQUIRE(radiance[2] == Approx(2.48244e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0310379, -0.0310379, 0.993134);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.54351e-06));
      // REQUIRE(radiance[1] == Approx(2.54351e-06));
      // REQUIRE(radiance[2] == Approx(2.54351e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0310039, -0.0310039, 0.993298);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.54679e-06));
      // REQUIRE(radiance[1] == Approx(2.54679e-06));
      // REQUIRE(radiance[2] == Approx(2.54679e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.03061, -0.03061, 0.993748);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.4186e-06));
      // REQUIRE(radiance[1] == Approx(2.4186e-06));
      // REQUIRE(radiance[2] == Approx(2.4186e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0315015, -0.0315015, 0.99422);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(1.19147));
      // REQUIRE(radiance[1] == Approx(1.19147));
      // REQUIRE(radiance[2] == Approx(1.19147));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0310906, -0.0310906, 0.994791);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.57731e-06));
      // REQUIRE(radiance[1] == Approx(2.57731e-06));
      // REQUIRE(radiance[2] == Approx(2.57731e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0304846, -0.0304846, 0.994989);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.35763e-06));
      // REQUIRE(radiance[1] == Approx(2.35763e-06));
      // REQUIRE(radiance[2] == Approx(2.35763e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0312818, -0.0312818, 0.995199);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(1.08305));
      // REQUIRE(radiance[1] == Approx(1.08305));
      // REQUIRE(radiance[2] == Approx(1.08305));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0314089, -0.0314089, 0.995341);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.67935e-06));
      // REQUIRE(radiance[1] == Approx(2.67935e-06));
      // REQUIRE(radiance[2] == Approx(2.67935e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0310816, -0.0310816, 0.995722);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.56107e-06));
      // REQUIRE(radiance[1] == Approx(2.56107e-06));
      // REQUIRE(radiance[2] == Approx(2.56107e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0315794, -0.0315794, 0.996203);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.75304e-06));
      // REQUIRE(radiance[1] == Approx(2.75304e-06));
      // REQUIRE(radiance[2] == Approx(2.75304e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0318869, -0.0318869, 0.996381);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(1.25848));
      // REQUIRE(radiance[1] == Approx(1.25848));
      // REQUIRE(radiance[2] == Approx(1.25848));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0306867, -0.0306867, 0.996614);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.43206e-06));
      // REQUIRE(radiance[1] == Approx(2.43206e-06));
      // REQUIRE(radiance[2] == Approx(2.43206e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0314202, -0.0314202, 0.996752);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(1.14216));
      // REQUIRE(radiance[1] == Approx(1.14216));
      // REQUIRE(radiance[2] == Approx(1.14216));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0306829, -0.0306829, 0.997098);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.45252e-06));
      // REQUIRE(radiance[1] == Approx(2.45252e-06));
      // REQUIRE(radiance[2] == Approx(2.45252e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0312299, -0.0312299, 0.997226);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(1.12156));
      // REQUIRE(radiance[1] == Approx(1.12156));
      // REQUIRE(radiance[2] == Approx(1.12156));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.031178, -0.031178, 0.997417);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.60689e-06));
      // REQUIRE(radiance[1] == Approx(2.60689e-06));
      // REQUIRE(radiance[2] == Approx(2.60689e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0319858, -0.0319858, 0.99757);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.88814e-06));
      // REQUIRE(radiance[1] == Approx(2.88814e-06));
      // REQUIRE(radiance[2] == Approx(2.88814e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.031036, -0.031036, 0.997765);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(1.1019));
      // REQUIRE(radiance[1] == Approx(1.1019));
      // REQUIRE(radiance[2] == Approx(1.1019));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0319669, -0.0319669, 0.99786);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.87288e-06));
      // REQUIRE(radiance[1] == Approx(2.87288e-06));
      // REQUIRE(radiance[2] == Approx(2.87288e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0310538, -0.0310538, 0.998095);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.57235e-06));
      // REQUIRE(radiance[1] == Approx(2.57235e-06));
      // REQUIRE(radiance[2] == Approx(2.57235e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.031004, -0.031004, 0.998173);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.52541e-06));
      // REQUIRE(radiance[1] == Approx(2.52541e-06));
      // REQUIRE(radiance[2] == Approx(2.52541e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0309691, -0.0309691, 0.998399);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(2.54405e-06));
      // REQUIRE(radiance[1] == Approx(2.54405e-06));
      // REQUIRE(radiance[2] == Approx(2.54405e-06));
    }
    {
      Vector3f rayOrigin(0, 0.65, -1.273);
      Vector3f rayDirection(-0.0308568, -0.0308568, 0.998474);
      Random rng;
      Vector3f radiance = to_test.getRadiance(rayOrigin, rayDirection, rng);
      // REQUIRE(radiance[0] == Approx(1.07722));
      // REQUIRE(radiance[1] == Approx(1.07722));
      // REQUIRE(radiance[2] == Approx(1.07722));
    }
}
