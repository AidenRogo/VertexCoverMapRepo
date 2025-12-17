
#ifndef VERTEXCOVERMAPREPO_MAIN_H
#define VERTEXCOVERMAPREPO_MAIN_H
#include "Graph.h"

void reduce_IS_to_VC(Graph *G, int k, Graph *G_prime, int *k_prime);

int solve_independent_set(Graph *G, int k);

#endif //VERTEXCOVERMAPREPO_MAIN_H