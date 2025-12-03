
#ifndef VERTEXCOVERMAPREPO_GRAPH_H
#define VERTEXCOVERMAPREPO_GRAPH_H

#include <iostream>
#include <vector>
#include <list>

// Define the Edge struct first
struct Edge {
    int src, dest;
};

class Graph
{
public:
    // vector to show adj list
    std::vector<std::vector<int>> adj_list;

    // Graph constructor
    Graph(std::vector<Edge> const& edges, int n) {
        // Stretch or shrink vector for number of elements
        adj_list.resize(n);

        // Make an edge for each point
        for (auto& edge : edges) {
            // Safety check: ensure the source is within the bounds of the list
            if (edge.src < n) {
                adj_list[edge.src].push_back(edge.dest);

                // Uncomment the line below for an undirected graph
                // adj_list[edge.dest].push_back(edge.src);
            }
        }
    }
};

// Helper function to print the graph
// Marked 'inline' to allow inclusion in multiple source files without linker errors
inline void print_graph(Graph const& graph, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << i << " > ";

        // Ensure we don't access out of bounds if n is larger than the list
        if (i < graph.adj_list.size()) {
            for (int v : graph.adj_list[i]) {
                std::cout << v << " ";
            }
        }
        std::cout << std::endl;
    }
}

#endif //VERTEXCOVERMAPREPO_GRAPH_H