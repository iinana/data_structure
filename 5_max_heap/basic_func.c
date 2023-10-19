#include "main.h"

int findParent(int child) {
    return (child - 1) / 2;
}

void swap(MaxHeap **heap, int idx1, int idx2) {
    int temp = (*heap)->elements[idx1];
    (*heap)->elements[idx1] = (*heap)->elements[idx2];
    (*heap)->elements[idx2] = temp;
}

int findLeftChild(int par) {
    return par * 2 + 1;
}

int findRightChild(int par) {
    return par * 2 + 2;
}