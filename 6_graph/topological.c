#include "main.h"
#include "queue.h"

int *topologicalSort(Vertex *graph, int numV) {
    int *topo = (int *)malloc(sizeof(int) * numV);
    Queue q = initializeQueue(numV);

    int *inDegree = (int *)malloc(sizeof(int) * numV);
    for (int i = 0; i < numV; i++) inDegree[i] = 0;

    for (int i = 0; i < numV; i++) {
        for (int j = 0; j < graph[i].degree; j++) {
            int x = graph[i].neighbor[j];
            inDegree[x]++;
        }
    }

    for (int i = 0; i < numV; i++) {
        if (inDegree[i] == 0) Qpush(&q, i);
    }

    int count = 0;
    while (!QisEmpty(q)) {
        int x = Qpop(&q);
        if (inDegree[x] == 0) {
            inDegree[x] = -1;
            topo[count] = x;
            count++;
        }
        
        for (int i = 0; i < graph[x].degree; i++) {
            int y = graph[x].neighbor[i];
            inDegree[y]--;
            if (inDegree[y] == 0) Qpush(&q, y);
        }
    }

    return topo;
}