#include "main.h"

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Correct Usage : [Program] [Input File] [Output File]\n");
        return 1;
    }

    FILE *inFile = fopen(argv[1], "r");
    FILE *outFile = fopen(argv[2], "w");
    if (!inFile || !outFile) {
        printf("File Open Failed\n");
        return 1;
    }

    char c;
    while ((c = fgetc(inFile)) != EOF) {
        if (!isalpha(c)) continue;
        if (c == 'T') {
            int n, len;
            fscanf(inFile, "%d", &n);
            fscanf(inFile, "%d", &len);

            Hash **hashTable = makeHashTable(inFile, len, n);

            if (TwoSum(hashTable, n)) fputc('T', outFile);
            else fputc('F', outFile);

            freeHash(hashTable, n);
        } 
        // else if (c == 'S') {
        // } 
        else fputs("Function Error", outFile);
        fputc('\n', outFile);
    }

    fclose(inFile);
    fclose(outFile);
}