#include "main.h"
#include "queue.h"

int *BFS(Vertex *graph, int numV) {
    int *bfs = (int *)malloc(sizeof(int) * numV);
    Queue que = initializeQueue(numV);
    bool *visited = (bool *)malloc(sizeof(bool) * numV);
    for (int i = 0; i < numV; i++) visited[i] = false;

    int count = 0;
    push(&que, 0);
    while (que.numItem != 0) {
        int v = pop(&que);
        if (!visited[v]) {
            bfs[count] = v;
            count++;
            visited[v] = true;
        }

        for (int i = 0; i < graph[v].degree; i++) {
            int q = graph[v].neighbor[i];
            if (visited[q]) continue;
            else push(&que, q);
        }
    }

    return bfs;
}

int *DFS(Vertex *graph, int numV) {
    int *dfs = (int *)malloc(sizeof(int) * numV);
    bool *visited = (bool *)malloc(sizeof(bool) * numV);
    for (int i = 0; i < numV; i++) visited[i] = false;



    return dfs;
}