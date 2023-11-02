#include "../hash/hash.h"

bool isSubset(Hash **par, Hash **sub) {
    for (int i = 0; i < HASH_LEN; i++) {
        if (sub[i]) {
            Hash *curr = sub[i];
            while (curr) {
                if (!Search(par, curr->value)) return false;
                curr = curr->next;
            }
        }
    }
    return true;
}

int main() {
    printf("Enter integers for an array : ");
    Hash **par = makeHashTable();
    getchar();

    printf("Enter intgers for subset : ");
    Hash **sub = makeHashTable();

    if (isSubset(par, sub)) printf("True\n");
    else printf("False\n");
}