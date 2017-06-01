Harrison Ainsworth (hxa7241)'s Minilight, in C++
================================================

Minilight is a raytracer. It takes scene files, in its own textual format,
and creates images, in .ppm format.

The original minilight-cpp repo is here: https://github.com/hxa7241/minilight-cpp

The build process is now using apenwarr redo: https://github.com/apenwarr/redo

The unit tests are now using catch: https://github.com/philsquared/Catch

To build minilight, do this:

```bash
./do minilight
```

To build and run the unit tests, do this:

```bash
./do test
```

To create a picture, build minilight and then do this:
```
./minilight scenes/cornellbox-m.ml.txt
```
The output is a .ppm file, which can be opened with, e.g. GIMP.

Dependencies: bash, g++