#include "main.h"
#include "queue.h"

Queue initializeQueue(int size) {
    Queue que;
    que.list = (int *)malloc(sizeof(int) * size);
    que.head = 0;
    que.tail = 0;
    que.numItem = 0;
    que.len = size;
    return que;
}

bool isEmpty(Queue que) {
    return (que.numItem == 0);
}

bool isFull(Queue que) {
    return (que.numItem == que.len);
}

void push(Queue *que, int q) {
    if (isFull(*que)) {
        printf("Queue is Full\n");
        return;
    }

    que->list[que->tail] = q;
    if (que->tail < (que->len - 1)) ++(que->tail);
    else que->tail = 0;
    ++(que->numItem);
}

int pop(Queue *que) {
    if (isEmpty(*que)) {
        printf("Queue is Empty\n");
        return -1;
    }

    int q = que->list[que->head];

    if (que->head < (que->len - 1)) ++(que->head);
    else que->head = 0;
    --(que->numItem);

    return q;
}