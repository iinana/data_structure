#pragma once
#include "main.h"

typedef struct QUEUE {
    int *list;
    int head;
    int tail;
    int numItem;
    int len;
} Queue;

Queue initializeQueue(int size);
void push(Queue *que, int q);
int pop(Queue *que);