#include "main.h"

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Correct Usage: [Program] [Input File] [Output File]\n");
        return 1;
    }

    FILE *inFile = fopen(argv[1], "r");
    FILE *outFile = fopen(argv[2], "w");
    if (!inFile || !outFile) {
        printf("File Open Failed\n");
        return 1;
    }

    char c;
    int len;
    Tries *tries = (Tries *)malloc(sizeof(Tries));
    while ((c = fgetc(inFile)) != EOF) {
        if (!isalpha(c)) continue;

        if (c == 'T') {
            fscanf(inFile, "%d", &len);
            tries = buildTries(inFile, len);
        } 
        else if (c == 'A') {
            char prefix[MAX_WORD_LEN];
            fscanf(inFile, "%s", prefix);

            char (*res)[MAX_WORD_LEN] = (char(*)[MAX_WORD_LEN])malloc(sizeof(char) * MAX_WORD_LEN * len);
            int num = autoComplete(prefix, tries, res);
            for (int i = 0; i < num; i++) fprintf(outFile, "%s ", res[i]);
            fputc('\n', outFile);
        } 
        else fputs("Function Error\n", outFile);
    }
    free(tries);
    fclose(inFile);
    fclose(outFile);
}