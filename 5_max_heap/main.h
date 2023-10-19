#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_CAPACITY 100

typedef struct MAXHEAP {
    int capacity;
    int count;
    int *elements;
} MaxHeap;

int findParent(int child);
void swap(MaxHeap **heap, int idx1, int idx2);
int findLeftChild(int par);
int findRightChild(int par);

bool Insert(MaxHeap **heap, int a);
bool Delete(MaxHeap **heap);
int Max(MaxHeap *heap);
