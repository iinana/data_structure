#pragma once

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORD_LEN 30
#define START_TRIES 1
#define END_TRIES 0

typedef struct TRIES {
    char ch;
    struct TRIES *next;
} Tries;

Tries *buildTries(FILE *inFile, int len);
void freeTries(Tries *tries);