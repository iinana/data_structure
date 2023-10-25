#include "main.h"
#include "queue.h"
#include "stack.h"

int *BFS(Vertex *graph, int numV) {
    int *bfs = (int *)malloc(sizeof(int) * numV);
    Queue que = initializeQueue(numV);
    bool *visited = (bool *)malloc(sizeof(bool) * numV);
    for (int i = 0; i < numV; i++) visited[i] = false;

    int count = 0;
    Qpush(&que, 0);
    while (que.numItem != 0) {
        int v = Qpop(&que);
        if (visited[v]) continue;
        
        bfs[count] = v;
        count++;
        visited[v] = true;

        for (int i = 0; i < graph[v].degree; i++) {
            int q = graph[v].neighbor[i];
            if (!visited[q]) Qpush(&que, q);
        }
    }

    for (int i = 0; i < numV; i++) {
        if (!visited[i]) {
            bfs[count] = i;
            count++;
        }
    }

    if (count != numV) return NULL;
    else return bfs;
}

int *DFS(Vertex *graph, int numV) {
    int *dfs = (int *)malloc(sizeof(int) * numV);
    bool *visited = (bool *)malloc(sizeof(bool) * numV);
    for (int i = 0; i < numV; i++) visited[i] = false;
    Stack s = initializeStack(numV);

    int count = 0;
    Spush(&s, 0);
    while (s.top != 0) {
        int v = Spop(&s);
        if (visited[v]) continue;

        dfs[count] = v;
        count++;
        visited[v] = true;

        for (int i = 0; i < graph[v].degree; i++) {
            int q = graph[v].neighbor[i];
            if (!visited[q]) Spush(&s, q);
        }
    }

    
    for (int i = 0; i < numV; i++) {
        if (!visited[i]) {
            dfs[count] = i;
            count++;
        }
    }
    if (count != numV) return NULL;
    else return dfs;
}