#include "main.h"

int autoComplete(char *prefix, Tries *tries, char (*res)[MAX_WORD_LEN]) {
    int k = 0;
    while (prefix[k] != '\0') {
        bool match = false;
        for (int i = 0; i < tries->childNum; i++) {
            if (tries->child[i]->ch == prefix[k]) {
                match = true;
                tries = tries->child[i];
            }
        }
        if (match == false) break;
        else k++;
    }
    if (prefix[k] != '\0') return 0;
    
    int count = 0;
    completeWord(prefix, strlen(prefix), &count, tries, res);
    return count;
}

void completeWord(char *word, int len, int *count, Tries *tries, char (*res)[MAX_WORD_LEN]) {
    if (tries->childNum == 0) {
        word[len] = '\0';
        strcpy(res[*count], word);
        ++(*count);
        return;
    }

    for (int i = 0; i < tries->childNum; i++) {
        word[len] = tries->child[i]->ch;
        completeWord(word, len+1, count, tries->child[i], res);
    }
}