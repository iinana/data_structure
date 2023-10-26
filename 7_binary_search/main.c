#include "main.h"

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Corrct Usage : [Program] [Input File] [Output File]\n");
        return 0;
    }

    FILE *inFile = fopen(argv[1], "r");
    FILE *outFile = fopen(argv[2], "w");
    if (!inFile || !outFile) {
        printf("Failed to Open File\n");
        return 0;
    }

    char c;
    while ((c = fgetc(inFile)) != EOF) {
        if (!isalpha(c)) continue;

        if (c == 'B') {
            int len, q;
            fscanf(inFile, "%d %d", &len, &q);

            int *nums = (int *)malloc(sizeof(int) * len);
            for (int i = 0; i < len; i++) fscanf(inFile, "%d", &nums[i]);

            int idx = BinarySearch(nums, 0, len-1, q);
            fprintf(outFile, "B %d %d\n", len, q); 
            if (idx == -1) fputc('N', outFile);
            else fprintf(outFile, "%d", idx);

            free(nums);
        }
        // else if (c == 'P') isPerfectSquare();
        else fputs("Function Error", outFile);
        fputc('\n', outFile);
    }

    fclose(inFile);
    fclose(outFile);
    return 0;
}