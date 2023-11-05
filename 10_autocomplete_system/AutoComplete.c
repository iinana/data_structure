#include "main.h"

int autoComplete(char *prefix, Tries *tries, char (*res)[MAX_WORD_LEN]) {
    int k = 0;
    while (prefix[k] != '\0') {
        bool match = false;
        for (int i = 0; i < tries->childNum; i++) {
            if (t->child[i]->ch == prefix[k]) {
                match = true;
                tries = tries->child[i];
            }
        }
        if (match == false) break;
        else k++;
    }
    if (prefix[k] != '\0') return 0;
    
    int len = tries->childNum;
    k = 0;
    // for (int i = 0; i < len; i++) {
    //     while (prefix[k] != '\0') {
    //         res[i][k] = prefix[k];
    //     }
        
    //     Tries *t = tries;
    //     while (t->childNum > 0) {

    //     }
    // }
    return len;
}