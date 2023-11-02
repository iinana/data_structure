#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct HASH {
    int value;
    struct HASH *next;
} Hash;

Hash **makeHashTable(FILE *inFile, int len, int HASH_LEN);
Hash **makeHashTableWithDefault(FILE *inFile, int len);
int hash(int value, int HASH_LEN);
Hash *makeHash(int v, Hash *n);
void freeHash(Hash **table, int HASH_LEN);

bool Search(Hash **table, int q, int HASH_LEN);