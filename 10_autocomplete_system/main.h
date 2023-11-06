#pragma once

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORD_LEN 30
#define START_TRIES 1

typedef struct TRIES {
    char ch;
    struct TRIES **child;
    int childNum;
} Tries;

Tries *buildTries(FILE *inFile, int len);
Tries *makeElement(char ch, int childLen);
void freeTries(Tries *t);

int autoComplete(char *prefix, Tries *tries, char (*res)[MAX_WORD_LEN]);
void completeWord(char *word, int len, int *count, Tries *tries, char (*res)[MAX_WORD_LEN]);