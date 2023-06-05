#include <vector>
#include <string>
#include <iostream>

#include "KMPStringMatching.h"

// Helper function that pre-computes the longest prefix-suffix array for the pattern
std::vector< int > preComputeLPSArray( const std::string& pattern )
{
    // Start by pre-computing the longest common prefix-suffix array (LPS)
    std::vector< int > lps( pattern.size(), 0 ); // initialize to all zeroes
    int previousLPS = 0;
    int i = 1;

    while ( i < pattern.size() )
    {
        if ( pattern[ previousLPS ] == pattern[ i ] )
        {
            lps[ i ] = previousLPS + 1;
            ++previousLPS;
            ++i;
        }
        else if ( previousLPS > 0 )
        {
            previousLPS = lps[ previousLPS - 1 ];
        }
        else
        {
            ++i;
        }
    }

    return lps;
}

int KMPStringMatchingAlgorithm( const std::string& text, const std::string& pattern )
{
    std::vector< int > lps = preComputeLPSArray( pattern );

    int i = 0; // text pointer
    int k = 0; // pattern pointer

    while ( i < text.size() )
    {
        if ( text[ i ] == pattern[ k ] )
        {
            // Check if we are at the end of the pattern, if so return the proper index
            if ( k == pattern.size() - 1 ) return i - (int) pattern.size() + 1;
            ++i;
            ++k;
        }
        else if ( k > 0 )
        {
            k = lps[ k - 1 ];
        }
        else
        {
            ++i;
        }
    }

    return -1;
}

void KMPStringMatchingMain()
{
    std::string text = "An exploit (from the English verb to exploit, meaning "
                       "\"to use something to one’s own advantage\") is a piece of software, a chunk of data, "
                       "or a sequence of commands that takes advantage of a bug or vulnerability to cause unintended "
                       "or unanticipated behavior to occur on computer software, hardware, or something electronic "
                       "(usually computerized). Such behavior frequently includes things like gaining control of "
                       "a computer system, allowing privilege escalation, or a denial-of-service (DoS or related DDoS) "
                       "attack. In lay terms, some exploit is akin to a 'hack'.";
    std::string pattern = "English";

    int patternStartIndex = KMPStringMatchingAlgorithm( text, pattern );

    std::cout << "\n\nPattern starts at index " << patternStartIndex << " in the given text\n\n";
}
