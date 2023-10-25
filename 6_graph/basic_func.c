#include "main.h"

Vertex *construct(int *from, int *to, int *wei, int numV, int numE) {
    Vertex *adj_list = (Vertex *)malloc(sizeof(Vertex) * numV);
    for (int i = 0 ; i < numV; i++) {
        Vertex v;
        v.degree = 0;
        v.neighbor = (int *)malloc(sizeof(int) * numV);
        v.weight = (int *)malloc(sizeof(int) * numV);

        adj_list[i] = v;
    }

    for (int i = 0; i < numE; i++) {
        int f = from[i];
        Vertex *v = &adj_list[f];

        v->neighbor[v->degree] = to[i];
        v->weight[v->degree] = wei[i];
        ++(v->degree);
    }
    return adj_list;
}

bool isEdge(Vertex *graph, int from, int to) {
    int deg = graph[from].degree;
    int *nei = graph[from].neighbor;

    for (int i = 0; i < deg; i++) {
        if (to == nei[i]) return true;
    }
    return false;
}