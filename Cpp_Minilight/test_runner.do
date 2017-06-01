DEPS=""
DEPS="$DEPS random.o random_test.o"
DEPS="$DEPS camera.o camera_test.o"
DEPS="$DEPS scene.o scene_test.o"
DEPS="$DEPS surface_point.o surface_point_test.o"
DEPS="$DEPS triangle.o triangle_test.o"
DEPS="$DEPS vector3f.o vector3f_test.o"
DEPS="$DEPS ray_tracer.o"
# DEPS="$DEPS ray_tracer.o ray_tracer_test.o"
DEPS="$DEPS image.o image_test.o"
DEPS="$DEPS spatial_index.o spatial_index_test.o"
DEPS="$DEPS test_runner.o"
redo-ifchange $DEPS
g++ -o $3 $DEPS

