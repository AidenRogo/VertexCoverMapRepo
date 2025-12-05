#include "main.h"
#include "Graph.h"
#include <iostream>

using namespace std;

void reduce_IS_to_VC(Graph *G, int k, Graph *G_prime, int *k_prime)
{
    return;

}

int solve_independent_set(Graph *G, int k)
{
    return 1;

}

int main()
{
    cout << "Reduction...";

    // Read graph from file
    Graph* graph = read_graph_from_file("input.txt");

    if (graph != nullptr) {
        cout << "Graph loaded successfully!" << endl;
        print_graph(*graph, graph->adj_list.size());

        // Your graph

        delete graph;
    } else {
        cout << "Failed to load graph." << endl;
    }

    return 0;
}
