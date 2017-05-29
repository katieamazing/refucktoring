COMPILER=g++
LINKER=g++
OPTI="-O3 -ffast-math"
LINK_OPTIONS=
LANG="-x c++ -ansi -std=c++98 -pedantic -fno-enforce-eh-specs -fno-rtti"
WARN="-Wall -Wextra -Wabi -Wold-style-cast -Wsign-promo -Woverloaded-virtual -Wcast-align -Wwrite-strings -Wpointer-arith -Wcast-qual -Wconversion -Wredundant-decls -Wdisabled-optimization"
ARCH="-mfpmath=sse -msse"
COMPILE_OPTIONS="-c $LANG $OPTI $ARCH $WARN"
redo-ifchange $2.cpp
$COMPILER $COMPILE_OPTIONS -MD -MF $2.d -o $3 $2.cpp 
read DEPS <$2.d
redo-ifchange ${DEPS#*:}



