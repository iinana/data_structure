#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define HASH_LEN 11

typedef struct HASH {
    int value;
    struct HASH *next;
} Hash;

Hash **makeHashTable(void);
int hash(int value);
Hash *makeHash(int v, Hash *n);

bool Search(Hash **table, int q);