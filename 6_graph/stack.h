#pragma once
#include "main.h"

typedef struct STACK {
    int top;
    int len;
    int *list;
} Stack;

Stack initializeStack(int size);
bool SisEmpty(Stack *s);
bool SisFull(Stack *s);
void Spush(Stack *s, char x);
int Spop(Stack *s);