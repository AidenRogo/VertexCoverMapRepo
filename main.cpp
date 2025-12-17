#include "main.cpp.h"
#include "Graph.h"
#include <iostream>

using namespace std;

// oracle call
// might use int
// TODO link oracle in build when provided
extern bool oracle(Graph *G, int k);

void reduce_IS_to_VC(Graph *G, int k, Graph *G_prime, int *k_prime)
{
    // G' = G
    int V = G->adj_list.size();
    G_prime->adj_list = G->adj_list;

    // The reduction mapping for the parameter is k' = |V| - k
    *k_prime = V - k;
}

int solve_independent_set(Graph *G, int k)
{
    // Create G_prime object (initially empty)
    Graph G_prime_obj({}, G->adj_list.size());
    int k_prime = 0;

    // Perform the reduction
    reduce_IS_to_VC(G, k, &G_prime_obj, &k_prime);

    // Call the Oracle on the reduced instance (G', k')
    bool result = oracle(&G_prime_obj, k_prime);
    cout << "Calling oracle..." << endl;
    cout << "G': " << endl;
    print_graph(G_prime_obj, G_prime_obj.adj_list.size());

    // If the oracle says YES for VC, then IS is YES
    return result ? 1 : 0;
    return 0;
}

int main()
{
    cout << "Reduction...";

    // Read graph and k from file
    auto [graph, k] = read_graph_from_file("input.txt");

    if (graph != nullptr)
    {
        cout << "Graph loaded successfully!" << endl;
        print_graph(*graph, graph->adj_list.size());

        // Solve the Independent Set problem using the reduction
        int result = solve_independent_set(graph, k);
        cout << "Independent Set of size " << k << " exists: " << (result ? "YES" : "NO") << endl;

        delete graph;
    } else \
  {
        cout << "Failed to load graph." << endl;
    }

    return 0;
}
