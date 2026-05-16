// heap.cpp
// Diba Mirza

#include "heap.h"
#include <iostream>
using std::cout;

// Builds a heap from the range [start, end) using the heapify algorithm
// Should run in O(n) time
Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end){
    vdata = vector<int>(start, end);
    for (int i = (n/2) - 1; i >= 0; i--) {
	int check = i;
        while (true) {
	    int smallNum = check;
	    if (2 * check + 1 < n && vdata[2 * check + 1] < vdata[smallNum]) {
	        smallNum = 2 * check + 1;
	    }
	    if (2 * check + 2 < n && vdata[2 * check + 2] < vdata[smallNum]) {
                smallNum = 2 * check + 2;
            }
	    if (smallNum == check) {break;}
	    std::swap(vdata[check], vdata[smallNum]);
	    check = smallNum;
	}
    }
}

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
    vdata.push_back(value);
    int check = vdata.size() - 1;
    while (i != 0) {
        if (vdata[(check - 1) / 2] <= vdata[check]) {break;}
	std::swap(vdata[(check - 1) / 2], vdata[i]);
	check = (check - 1) / 2;
    }
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
    vdata[0] = vdata.back();
    vdata.pop_back();
    int check = 0;
    while (true) {
        int smallNum = check;
        if (2 * check + 1 < n && vdata[2 * check + 1] < vdata[smallNum]) {
            smallNum = 2 * check + 1;
  	}
        if (2 * check + 2 < n && vdata[2 * check + 2] < vdata[smallNum]) {
            smallNum = 2 * check + 2;
        }
        if (smallNum == check) {break;}
        std::swap(vdata[check], vdata[smallNum]);
        check = smallNum;
    }
}

// Returns the minimum element in the heap
int Heap::top(){
  return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  return vdata.empty();
}
    
