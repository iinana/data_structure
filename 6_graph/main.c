#include "main.h"
#include "queue.h"
#include "stack.h"

int main(int args, char **argv) {
    if (args != 3) {
        printf("Correct Usage : [Program] [Input File] [Output File]\n");
        return 0;
    }

    FILE *inFile = fopen(argv[1], "r");
    FILE *outFile = fopen(argv[2], "w");
    if (!inFile || !outFile) {
        printf("Failed to open file\n");
        return 0;
    }

    char c;
    int numV, numE;
    Vertex *graph;
    while ((c = fgetc(inFile)) != EOF) {
        if (!isalpha(c)) continue;

        if (c == 'C') {
            fscanf(inFile, "%d", &numV);
            fscanf(inFile, "%d", &numE);

            int *from = (int *)malloc(sizeof(int) * numE);
            int *to = (int *)malloc(sizeof(int) * numE);
            int *wei = (int *)malloc(sizeof(int) * numE);
            for (int i = 0; i < numE; i++) {
                fscanf(inFile, "%d", &from[i]);
                fscanf(inFile, "%d", &to[i]);
                fscanf(inFile, "%d", &wei[i]);
            }

            graph = construct(from, to, wei, numV, numE);
            if (!graph) {
                printf("Construction Error");
                return 0;
            } else fputc('C', outFile);

            for (int i = 0; i < numV; i++) {
                printf("%d | ", i);
                for (int j = 0; j < graph[i].degree; j++) {
                    printf("( %d, %d ) ", graph[i].neighbor[j], graph[i].weight[j]);
                }
                printf("\n");
            }
        }
        else if (c == 'I') {
            int from, to;
            fscanf(inFile, "%d", &from);
            fscanf(inFile, "%d", &to);

            fprintf(outFile, "%d %d ", from, to);
            if (isEdge(graph, from, to)) fputc('T', outFile);
            else fputc('F', outFile);
        }
        else if (c == 'N') {
            int n;
            fscanf(inFile, "%d", &n);
            
            fprintf(outFile, "[%d] ", n);
            for (int i = 0; i < graph[n].degree; i++) fprintf(outFile, "%d ", graph[n].neighbor[i]);
        }
        else if (c == 'B') {
            int *bfs = BFS(graph, numV);
            if (bfs) {
                fputc('B', outFile);
                for (int i = 0; i < numV; i++) fprintf(outFile, " %d", bfs[i]);
            } else fputs("BFS Traversal Error", outFile);
        }
        else if (c == 'D') {
            int *dfs = DFS(graph, numV);
            if (dfs) {
                fputc('D', outFile);
                for (int i = 0; i < numV; i++) fprintf(outFile, " %d", dfs[i]);
            } else fputs("DFS Traversal Error", outFile);
        }
        else if (c == 'T') {
            int *t = topologicalSort(graph, numV);
            if (t) {
                fputc('T', outFile);
                for (int i = 0; i < numV; i++) fprintf(outFile, " %d", t[i]);
            } else fputs("Topological Sort Error", outFile);
        }
        else fputs("Function Error", outFile);
        fputc('\n', outFile);
    }

    for (int i = 0; i < numV; i++) {
        free(graph[i].neighbor);
        free(graph[i].weight);
    }
    free(graph);

    return 0;
}