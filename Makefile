CXX = g++
CXXFLAGS = -std=c++17 -Wall
all: examheap
examheap: examheap.cpp heap.cpp
	$(CXX) $(CXXFLAGS) examheap.cpp heap.cpp -o examheap

clean:
	rm -f examheap
