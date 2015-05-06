#cflags=-std=c++11 -stdlib=libc++ -I/usr/include/x86_64-linux-gnu/c++/4.9 -I/usr/include/c++/4.9
CXX=g++
CXXFLAGS=-std=c++11
all:
	mkdir -p build
	$(CXX) $(CXXFLAGS) cprimes.cpp -o build/cprimes

test:
	mkdir -p build
	$(CXX) $(FLAGS) test.cpp -o build/test -Isrc/
	./build/test

clean:
	rm -r build/
