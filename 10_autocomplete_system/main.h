#pragma once

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORD_LEN 30
#define START_TRIES 1
#define END_TRIES 0

typedef struct TRIES {
    char ch;
    struct TRIES **child;
    int childNum;
} Tries;

Tries *buildTries(FILE *inFile, int len);
Tries *makeElement(char ch, int childLen);