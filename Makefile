CXX=clang++
CXXFLAGS=-std=c++14 -stdlib=libstdc++
all:
	mkdir -p build
	$(CXX) $(CXXFLAGS) cprimes.cpp -o build/cprimes

test:
	mkdir -p build
	$(CXX) $(FLAGS) test.cpp -o build/test -Isrc/
	./build/test

clean:
	rm -r build/
