#include "main.h"

bool Insert(MaxHeap **heap, int a) {
    if ((*heap)->count >= (*heap)->capacity) return false; 
    if ((*heap)->count == 0) {
        (*heap)->elements[0] = a;
        (*heap)->count += 1;
        return true;
    }

    int curidx = (*heap)->count;
    int paridx = findParent(curidx);

    (*heap)->elements[curidx] = a;
    while ((*heap)->elements[curidx] > (*heap)->elements[paridx]) {
        swap(heap, curidx, paridx);
        curidx = paridx;
        paridx = findParent(curidx);
    }
    (*heap)->count += 1;
    return true;
}

bool Delete(MaxHeap **heap) {
    if ((*heap)->count == 0) return false;

    swap(heap, 0, (*heap)->count - 1);
    int curidx = 0;
    int left = 1;
    int right = 2;

    while (((*heap)->elements[curidx] < (*heap)->elements[left]) || ((*heap)->elements[curidx] < (*heap)->elements[right])) {
        if (((*heap)->elements[left] > (*heap)->elements[right])) {
            if (left >= (*heap)->count) break;

            swap(heap, curidx, left);
            curidx = left;
            left = findLeftChild(curidx);
            right = findRightChild(curidx);
        }
        else {
            if (right >= (*heap)->count) break;

            swap(heap, curidx, right);
            left = findLeftChild(curidx);
            right = findRightChild(curidx);
        }
    }

    (*heap)->count -= 1;
    return true;
}

int Max(MaxHeap *heap) {
    if (heap->count == 0) return NULL;
    else return heap->elements[0];
}