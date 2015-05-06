#cflags=-std=c++11 -stdlib=libc++ -I/usr/include/x86_64-linux-gnu/c++/4.9 -I/usr/include/c++/4.9
CXX=g++
CXXFLAGS=-std=c++11
all:
	$(CXX) $(CXXFLAGS) cprimes.cpp -o cprimes

test:
	$(CXX) $(FLAGS) test.cpp -o test -Isrc/
	./test
