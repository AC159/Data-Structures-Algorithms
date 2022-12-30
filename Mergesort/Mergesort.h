#ifndef ALGORITHMS_MERGESORT_H
#define ALGORITHMS_MERGESORT_H

#include <vector>
#include <iostream>

using std::vector;

vector< int > mergeArrays( vector< int >& s1, vector< int >& s2 );
vector< int > mergeSort( vector< int >& nums, int low, int high );
void mergesortMain();

#endif //ALGORITHMS_MERGESORT_H
