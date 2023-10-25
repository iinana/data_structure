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
bool QisEmpty(Queue que);
bool QisFull(Queue que);
void Qpush(Queue *que, int q);
int Qpop(Queue *que);