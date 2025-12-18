
#ifndef VERTEXCOVERMAPREPO_GRAPH_H
#define VERTEXCOVERMAPREPO_GRAPH_H

#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <sstream>
#include <utility>

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
    Graph(std::vector<Edge> const& edges, int n)
    {
        // Stretch or shrink vector for number of elements
        adj_list.resize(n);

        // Make an edge for each point
        for (auto& edge : edges)
        {
            // Safety check: ensure the source is within the bounds of the list
            if (edge.src < n)
            {
                adj_list[edge.src].push_back(edge.dest);

                // undirected graph
                adj_list[edge.dest].push_back(edge.src);
            }
        }
    }
};

// Helper function to print the graph
// Marked 'inline' to allow inclusion in multiple source files without linker errors
inline void print_graph(Graph const& graph, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << i << " > ";

        // Ensure we don't access out of bounds if n is larger than the list
        if (i < graph.adj_list.size())
        {
            for (int v : graph.adj_list[i])
            {
                std::cout << v << " ";
            }
        }
        std::cout << std::endl;
    }
}

// Helper function to read graph from file
// File format: First line: n (number of vertices), second line: k, then each subsequent line: "src dest" for edges
inline std::pair<Graph*, int> read_graph_from_file(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return {nullptr,0};
    }

    int n; // number of vertices
    int k;
    file >> n >> k;

    std::vector<Edge> edges;
    int src, dest;

    // Read edges from file
    while (file >> src >> dest)
    {
        edges.push_back({src, dest});
    }

    file.close();

    return {new Graph(edges, n), k};

}

#endif //VERTEXCOVERMAPREPO_GRAPH_H