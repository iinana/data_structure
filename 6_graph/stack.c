#include "main.h"
#include "stack.h"

Stack initializeStack(int size) {
    Stack s;
    s.len = size;
    s.list = (int *)malloc(sizeof(int) * size);
    s.top = 0;

    return s;
}

bool SisEmpty(Stack *s) {
    return (s->top == 0);
}

bool SisFull(Stack *s) {
    return (s->top == s->len);
}

void Spush(Stack *s, char x) {
    if (SisFull(s)) {
        printf("[Error] Stack is full\n");
        return;
    }

    s->list[s->top] = x;
    ++(s->top);
}

int Spop(Stack *s) {
    if (SisEmpty(s)) {
        printf("[Error] Stack is empty\n");
        return '\0';
    }

    --(s->top);
    return s->list[s->top];
}