#include <vector>
#include <string>
#include <iostream>

#include "LevenshteinEditDistance.h"

int levenshteinEditDistance( std::string word1, std::string word2 )
{
    /*
        In each sub-problem, we take the minimum of each possible operation and add 1 to it (lines 46-48)
           |-----------|--------------|
           | Replace   |   Insert     |
           |-----------|--------------|
           | Delete    | Current cell |
           |-----------|--------------|
     */

    // Set up the DP table
    std::vector< std::vector< int > > editDistances( word2.size() + 1, std::vector< int >( word1.size() + 1, 0 ) );

    // Fill the first row
    for ( int i = 0; i <= word1.size(); ++i )
    {
        editDistances[ 0 ][ i ] = i;
    }

    // Fill the first column
    for ( int i = 0; i <= word2.size(); ++i )
    {
        editDistances[ i ][ 0 ] = i;
    }

    // Now we can fill the rest of the table
    for ( int i = 1; i <= word2.size(); ++i )
    {
        for ( int j = 1; j <= word1.size(); ++j )
        {
            if ( word1[ j - 1 ] == word2[ i - 1 ] )
            {
                /* If the characters are the same then the edit distance of this sub-problem is the same as
                   if the characters were not included */
                editDistances[ i ][ j ] = editDistances[ i - 1 ][ j - 1 ];
            }
            else
            {
                editDistances[ i ][ j ] = std::min( editDistances[ i - 1 ][ j - 1 ],
                                                    std::min( editDistances[ i ][ j - 1 ],
                                                              editDistances[ i - 1 ][ j ] ) ) + 1;
            }
        }
    }

    int distance = editDistances[ word2.size() ][ word1.size() ];
    std::cout << "The edit distance between '" << word1 << "' & '" << word2 << "' is " << distance << std::endl;

    return distance;
}

void levenshteinEditDistanceMain()
{
    std::cout << "\n";
    levenshteinEditDistance( "", "a" );
    levenshteinEditDistance( "a", "a" );
    levenshteinEditDistance( "a", "h" );
    levenshteinEditDistance( "horse", "ros" );
    levenshteinEditDistance( "cat", "dog" );
}
