#include "main.h"

Tries *buildTries(FILE *inFile, int len) {
    Tries *tries = makeElement(START_TRIES, len);

    for (int i = 0; i < len; i++) {
        char c = fgetc(inFile);
        while (!isalpha(c)) c = fgetc(inFile);
        Tries *t = tries;

        while (t->childNum != 0) {
            if (!isalpha(c)) break;

            bool match = false;
            for (int i = 0; i < t->childNum; i++) {
                if (t->child[i]->ch == c) {
                    match = true;
                    t = t->child[i];
                }
            }
            if (match == false) break;
            else c = fgetc(inFile);
        }
        
        while (isalpha(c)) {
            t->child[t->childNum] = makeElement(c, len);
            ++(t->childNum);

            t = t->child[t->childNum-1];
            c = fgetc(inFile);
        }
    }
    return tries;
}

Tries *makeElement(char ch, int childLen) {
    Tries *tries = (Tries *)malloc(sizeof(Tries));
    tries->ch = ch;
    tries->child = (Tries **)malloc(sizeof(Tries *) * childLen);
    tries->childNum = 0;
    return tries;
}