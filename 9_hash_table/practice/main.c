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
        else if (c == 'S') {
            int n;
            fscanf(inFile, "%d", &n);

            Hash **hashTable = (Hash **)malloc(sizeof(Hash) * n);
            for (int i = 0; i < n; i++) hashTable[i] = NULL;

            int key, value;
            for (int i = 0; i < n; i++) {
                fscanf(inFile, "%d", &key);
                fscanf(inFile, "%d", &value);
                if (hashTable[key]) {
                    Hash *cur = hashTable[key];
                    while (cur->next) cur = cur->next;
                    cur->next = makeHash(value, NULL);
                } else hashTable[key] = makeHash(value, NULL);
            }

            int (*res)[2] = SymmetricPairs(hashTable, n);
            if (res) {
                int i = 0;
                while (res[i][0]) {
                    fprintf(outFile, "( %d , %d )  ", res[i][0], res[i][1]); 
                    i++;
                }
            } else fputs("Symmetirc Pairs Search Failed", outFile);
            free(res);
        } 
        else fputs("Function Error", outFile);
        fputc('\n', outFile);
    }

    fclose(inFile);
    fclose(outFile);
}