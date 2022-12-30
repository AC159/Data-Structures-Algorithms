#include "QuickSort.h"

#include <iostream>
#include <vector>

void quicksort( std::vector< int >& sequence, int low, int high )
{
    if ( low < high )
    {
        int pivot = sequence[ high ];
        int i = low - 1;
        int j = low;

        for ( ; j < high; ++j )
        {
            if ( sequence[ j ] <= pivot )
            {
                ++i;
                std::swap( sequence[ i ], sequence[ j ] );
            }
        }

        // Perform one last swap to place the pivot to its right position
        std::swap( sequence[ ++i ], sequence[ high ] );

        // Recurse on the two sub-sequences
        quicksort( sequence, low, i - 1 );
        quicksort( sequence, i + 1, high );
    }
}

void quicksortMain()
{
    std::srand( time( NULL ) );

    int sequenceSize = 100;
    std::vector< int > sequence( sequenceSize );

    for ( int i = 0; i < sequenceSize; ++i )
    {
        sequence[ i ] = std::rand() % 1000;
    }

    quicksort( sequence, 0, sequenceSize - 1 );

    std::cout << "Sorted vector with quicksort: \n[";
    for ( int i = 0; i < sequenceSize; ++i )
    {
        if ( i % 10 == 0 ) std::cout << "\n";
        if ( i != sequenceSize - 1 ) std::cout << sequence[ i ] << ", ";
        else std::cout << sequence[ i ];
    }
    std::cout << "]\n";
}
