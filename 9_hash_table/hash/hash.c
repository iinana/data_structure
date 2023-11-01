#include "hash.h"

Hash **makeHashTable(void) {
    Hash **hashTable = (Hash **)malloc(sizeof(Hash) * HASH_LEN);
    for (int i = 0; i < HASH_LEN; i++) hashTable[i] = NULL;
    int input, key;

    while (scanf("%d", &input) == 1) {
        Hash *h = makeHash(input, NULL);
        key = hash(input);

        if (hashTable[key]) {
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

bool Search(Hash **table, int q) {
    int key = hash(q);
    Hash *curr = table[key];

    while (curr) {
        if (q == curr->value) return true;
        curr = curr->next;
    }
    return false;
}