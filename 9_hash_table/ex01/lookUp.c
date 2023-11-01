#include "../hash/hash.h"

bool isRepeated(Hash **hashTable) {
    for (int i = 0; i < HASH_LEN; i++) {
        if (hashTable[i]) {
            Hash *cur = hashTable[i];
            while (cur->next) {
                int q = cur->value;
                Hash *n = cur->next;
                while (n) {
                    if (q == n->value) return true;
                    n = n->next;
                }
                cur = cur->next;
            }
        }
    }
    return false;
}

int main() {
    printf("Enter the Integers: ");
    Hash **hashTable = makeHashTable();

    if (isRepeated(hashTable)) printf("Repeated Value : True\n");
    else printf("Repeated Value : False\n");
}