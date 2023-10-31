#include "main.h"

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Correct Usage : [Program] [Input File] [Output File]\n");
        return 1;
    }

    FILE *inFile = fopen(argv[1], "r");
    FILE *outFile = fopen(argv[2], "w");
    if (!inFile || !outFile) {
        printf("Failed to Open File\n");
        return 1;
    }

    char c;
    while ((c = fgetc(inFile)) != EOF) {
        if (!isalpha(c)) continue;
        if (c == 'M') {
            int len;
            fscanf(inFile, "%d", &len);

            int *nums = (int *)malloc(sizeof(int) * len);
            for (int i = 0; i < len; i++) fscanf(inFile, "%d", &nums[i]);

            if (mergeDescending(nums, 0, len-1)) {
                fputc('M', outFile);
                for (int i = 0; i < len; i++) fprintf(outFile, " %d", nums[i]); 
            } else fputs("Merge Sort Error", outFile);
            free(nums);
        }
        else if (c == 'Q') {
            int len;
            fscanf(inFile, "%d", &len);
            int *nums = (int *)malloc(sizeof(int) * len);
            for (int i = 0; i < len; i++) fscanf(inFile, "%d", &nums[i]);

            if (quickDescending(nums, 0, len-1)) {
                fputc('Q', outFile);
                for (int i = 0; i < len; i++) fprintf(outFile, " %d", nums[i]);
            } else fputs("Quick Sort Error", outFile);
        }
        else fputs("Function Error", outFile);
        fputc('\n', outFile);
    }

    fclose(inFile);
    fclose(outFile);
}