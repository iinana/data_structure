#include "main.h"

int main(int args, char **argv) {
    if (args != 3) {
        printf("Corrct Usage : [program] [input file] [output file]\n");
        return 1;
    }

    FILE *inFile = fopen(argv[1], "r");
    FILE *outFile = fopen(argv[2], "w");
    char c;

    MaxHeap *heap = (MaxHeap *)malloc(sizeof(MaxHeap));
    heap->capacity = MAX_CAPACITY;
    heap->count = 0;
    heap->elements = (int *)malloc(sizeof(int) * heap->capacity);

    while ((c = fgetc(inFile)) != EOF) {
        if (!isalpha(c)) continue;
        
        if (c == 'I') {
            int a; 
            fscanf(inFile, "%d", &a);
            
            if (Insert(&heap, a)) {
                fputc('I', outFile);
                for (int i = 0; i < heap->count; i++) fprintf(outFile, " %d", heap->elements[i]);
            } else {
                printf("[Error] Insertion Failed\n");
                return 1;
            } 
        } else if (c == 'D') {
            if (Delete(&heap)) {
                fputc('D', outFile);
                for (int i = 0; i < heap->count; i++) fprintf(outFile, " %d", heap->elements[i]);
            } else {
                printf("[Error] Deletion Failed\n");
                return 1;
            }
        }
        else if (c == 'M') {
            int max = Max(heap);
            if (max) fprintf(outFile, "M %d", max);
            else {
                printf("[Error] Max Find Failed\n");
                return 1;
            }
        }
        else fputs("[Error] NO FUNCTION\n", outFile);
        fputc('\n', outFile);
    }
}