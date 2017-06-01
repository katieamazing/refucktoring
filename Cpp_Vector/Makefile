test: test_runner
	./test_runner

test_runner: random.o test_runner.o vector3f.o vector3f_test.o
	g++ -o test_runner random.o test_runner.o vector3f.o vector3f_test.o

random.o: random.cpp random.h hxa7241_general.h primitives.h
	g++ -c -o random.o random.cpp

test_runner.o: test_runner.cpp catch.h
	g++ -c -o test_runner.o test_runner.cpp

vector3f.o: vector3f.cpp vector3f.h hxa7241_graphics.h primitives.h
	g++ -c -o vector3f.o vector3f.cpp

vector3f_test.o: vector3f_test.cpp catch.h vector3f.h hxa7241_graphics.h primitives.h random.h hxa7241_general.h
	g++ -c -o vector3f_test.o vector3f_test.cpp

clean:
	rm test_runner random.o test_runner.o vector3f.o vector3f_test.o

