#ifndef ALGORITHMS_KMPSTRINGMATCHING_H
#define ALGORITHMS_KMPSTRINGMATCHING_H

#include <string>

std::vector< int > preComputeLPSArray( const std::string& pattern );

int KMPStringMatchingAlgorithm( const std::string& text, const std::string& pattern );

void KMPStringMatchingMain();

#endif //ALGORITHMS_KMPSTRINGMATCHING_H
