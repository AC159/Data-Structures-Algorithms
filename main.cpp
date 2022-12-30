#include <iostream>
#include <queue>
#include <functional>

#include "Quicksort/QuickSort.h"
#include "Dijkstra/Dijkstra.h"
#include "KMPStringMatching/KMPStringMatching.h"
#include "LevenshteinEditDistance/LevenshteinEditDistance.h"
#include "Mergesort/Mergesort.h"

void showpq( std::priority_queue< int, std::vector< int >, std::function< bool( int, int )>> gq )
{
    std::priority_queue< int, std::vector< int >, std::function< bool( int, int )>> g = gq;
    while ( !g.empty() )
    {
        std::cout << '\t' << g.top();
        g.pop();
    }
    std::cout << '\n';
}

int main()
{
    quicksortMain();

    mergesortMain();

    std::vector< int > v1 = { 20, 30, 40, 25, 15 };

    // Converting vector into a max heap
    // using make_heap()
    make_heap( v1.begin(), v1.end() );

    // Displaying the maximum element of heap
    // using front()
    std::cout << "\nThe maximum element of heap is: ";
    std::cout << v1.front() << std::endl;

    std::pop_heap( v1.begin(), v1.end() );

    std::cout << "\nThe maximum element of heap is: ";
    std::cout << v1.front() << std::endl;

    v1.push_back( 50 );
    make_heap( v1.begin(), v1.end() );
    std::cout << "\nThe maximum element of heap is: ";
    std::cout << v1.front() << std::endl;

    auto lambda = []( int a, int b ) -> bool
    {
        if ( a >= b ) return true; // min heap
        return false;
    };

    std::priority_queue< int, std::vector< int >, std::function< bool( int, int )>> gquiz( lambda );
    gquiz.push( 10 );
    gquiz.push( 30 );
    gquiz.push( 20 );
    gquiz.push( 5 );
    gquiz.push( 1 );

    std::cout << "\nThe priority queue gquiz is: ";
    showpq( gquiz );

    dijkstraMain();

    KMPStringMatchingMain();

    levenshteinEditDistanceMain();

    return 0;
}
