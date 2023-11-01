#include "hash.h"

Hash **makeHashTable(void) {
    Hash **hashTable = (Hash **)malloc(sizeof(Hash) * HASH_LEN);
    for (int i = 0; i < HASH_LEN; i++) hashTable[i] = makeHash('\0', NULL);
    int input, key;

    while (scanf("%d", &input) == 1) {
        Hash *h = makeHash(input, NULL);
        key = hash(input);

        if (hashTable[key]->value) {
            Hash *cur = hashTable[key];
            while (cur->next) cur = cur->next;
            cur->next = h;
        } else hashTable[key] = h;
    }

    return hashTable;
}

int hash(int value) { return value % HASH_LEN; }

Hash *makeHash(int v, Hash *n) {
    Hash *h = (Hash *)malloc(sizeof(Hash));
    h->value = v;
    h->next = n;
    return h;
}