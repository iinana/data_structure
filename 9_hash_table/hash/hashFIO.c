#include "hashFIO.h"

Hash **makeHashTableWithDefault(FILE *inFile, int len) {
    return makeHashTable(inFile, len, 11);
}

Hash **makeHashTable(FILE *inFile, int len, int HASH_LEN) {
    Hash **hashTable = (Hash **)malloc(sizeof(Hash) * HASH_LEN);
    for (int i = 0; i < HASH_LEN; i++) hashTable[i] = NULL;
    int input, key;

    for (int i = 0; i < len; i++) {
        fscanf(inFile, "%d", &input);
        Hash *h = makeHash(input, NULL);
        key = hash(input, HASH_LEN);

        if (hashTable[key]) {
            Hash *cur = hashTable[key];
            while (cur->next) cur = cur->next;
            cur->next = h;
        } else hashTable[key] = h;
    }

    return hashTable;
}

int hash(int value, int HASH_LEN) { return value % HASH_LEN; }

Hash *makeHash(int v, Hash *n) {
    Hash *h = (Hash *)malloc(sizeof(Hash));
    h->value = v;
    h->next = n;
    return h;
}

bool Search(Hash **table, int q, int HASH_LEN) {
    int key = hash(q, HASH_LEN);
    Hash *curr = table[key];

    while (curr) {
        if (q == curr->value) return true;
        curr = curr->next;
    }
    return false;
}

void freeHash(Hash **table, int HASH_LEN) {
    for (int i = 0; i < HASH_LEN; i++) {
        if (table[i]) free(table[i]);
    }
    free(table);
}