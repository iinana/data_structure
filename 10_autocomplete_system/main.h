#pragma once

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORD_LEN 30
#define START_TRIES 1

typedef struct TRIES {
    char ch;
    struct TRIES **child;
    int childNum;
} Tries;

Tries *buildTries(FILE *inFile, int len);
Tries *makeElement(char ch, int childLen);

int autoComplete(char *prefix, Tries *tries, char (*res)[MAX_WORD_LEN]);