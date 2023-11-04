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
    Tries *tries = (Tries *)malloc(sizeof(Tries));
    while ((c = fgetc(inFile)) != EOF) {
        if (!isalpha(c)) continue;

        if (c == 'T') {
            int len;
            fscanf(inFile, "%d", &len);

            tries = buildTries(inFile, len);
            break;
        } else if (c == 'A') {
        } else fputs("Function Error\n", outFile);
    }

    freeTries(tries);
    fclose(inFile);
    fclose(outFile);
}