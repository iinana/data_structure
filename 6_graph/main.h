#pragma once

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"
#include "stack.h"

typedef struct VERTEX {
    int *weight;
    int *neighbor;
    int degree;
} Vertex;

Vertex *construct(int *from, int *to, int *wei, int numV, int numE);
bool isEdge(Vertex *graph, int from, int to);

int *BFS(Vertex *graph, int numV);
int *DFS(Vertex *graph, int numV);

int *topologicalSort(Vertex *graph, int numV);