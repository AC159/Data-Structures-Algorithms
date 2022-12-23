#ifndef ALGORITHMS_DIJKSTRA_H
#define ALGORITHMS_DIJKSTRA_H


#include <vector>

int shortestPaths( const std::vector<int>& dist, int graphSize, const std::vector<bool>& processedNodes );
std::vector<int> dijkstra( std::vector<std::vector<int>> graph, int source );
void dijkstraMain();

#endif //ALGORITHMS_DIJKSTRA_H
