DEPS="camera.o image.o random.o ray_tracer.o scene.o spatial_index.o surface_point.o triangle.o vector3f.o minilight.cpp"
redo-ifchange $DEPS
g++ -o $3 $DEPS
