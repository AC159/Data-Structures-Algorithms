cmake_minimum_required(VERSION 3.23)
project(Algorithms)

set(CMAKE_CXX_STANDARD 20)

add_executable(Algorithms main.cpp Quicksort/QuickSort.cpp Quicksort/QuickSort.h Dijkstra/Dijkstra.cpp Dijkstra/Dijkstra.h KMPStringMatching/KMPStringMatching.cpp KMPStringMatching/KMPStringMatching.h LevenshteinEditDistance/LevenshteinEditDistance.h LevenshteinEditDistance/LevenshteinEditDistance.cpp Mergesort/Mergesort.h Mergesort/Mergesort.cpp BinarySearch/BinarySearch.h BinarySearch/BinarySearch.cpp Trie/Trie.cpp Trie/Trie.h)
