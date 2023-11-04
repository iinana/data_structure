#include "main.h"

Tries *buildTries(FILE *inFile, int len) {
    Tries *tries = makeElement(START_TRIES, NULL);

    for (int i = 0; i < len; i++) {
        char c;
        while ((c = fgetc(inFile)) != ' ') {
            if (tries->next) {
                Tries *t = tries->next;
                
            }
        }
    }
    
    return tries;
}

Tries *makeElement(char ch, Tries *next) {
    Tries *tries = (Tries *)malloc(sizeof(Tries));
    tries->ch = ch;
    tries->next = next;

    return tries;
}

void freeTries(Tries *tries) {
    Tries *first = tries;
    while(first->next) {
        Tries *n = first->next;
        free(first);
        first = n;
    }
    free(first);
}