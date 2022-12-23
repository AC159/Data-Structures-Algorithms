#include <iostream>
#include <vector>
#include <set>

#include "Dijkstra.h"

#define INF (INT32_MAX / 10)

// Potential optimization is to use a priority queue instead of a linear search for the min node
int shortestPaths( const std::vector< int >& dist, int graphSize, const std::vector< bool >& processedNodes )
{
    int minValue = INF;
    int minNode = 0;
    for ( int j = 0; j < graphSize; ++j )
    {
        if ( !processedNodes[ j ] && dist[ j ] < minValue )
        {
            minNode = j;
            minValue = dist[ j ];
        }
    }
    return minNode;
}

std::vector< int > dijkstra( std::vector< std::vector< int>> graph, int source )
{
    // Initialize the initial paths from source to destinations
    std::vector< int > dist( graph.size(), INF );
    dist[ source ] = 0;
    std::vector< bool > processedNodes( graph.size(), false );

    for ( int i = 0; i < graph.size(); ++i )
    {
        // Find the node with the shortest path
        int u = shortestPaths( dist, graph.size(), processedNodes );
        processedNodes[ u ] = true;

        // Update the distances of all the vertices that are adjacent to u and which have not been processed
        for ( int v = 0; v < graph.size(); ++v )
        {
            if ( !processedNodes[ v ] )
            {
                dist[ v ] = std::min( dist[ v ], dist[ u ] + graph[ u ][ v ] );
            }
        }
    }

    return dist;
}

void dijkstraMain()
{
    // Adjacency matrix representation of a graph with edge weights
    std::vector< std::vector< int>> graph = {
            { 0,   2,   INF, INF, INF, INF, INF, 3 },
            { 2,   0,   2,   INF, INF, INF, INF, 1 },
            { INF, 2,   0,   INF, 4,   INF, INF, INF },
            { INF, INF, INF, 0,   3,   10,  INF, INF },
            { INF, INF, 4,   3,   0,   INF, 2,   10 },
            { INF, INF, INF, 10,  INF, 0,   INF, 5 },
            { INF, INF, INF, INF, 2,   INF, 0,   INF },
            { 3,   1,   INF, INF, 10,  INF, INF, 0 }
    };

    // Getting the shortest paths from source node 3
    std::vector< int > shortestPaths = dijkstra( graph, 3 );
    std::cout << "Dijkstra shortest paths: \n[";
    for ( int path : shortestPaths ) std::cout << path << ", ";
    std::cout << "]";
}
