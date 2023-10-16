#include "main.h"
#include "stack.h"

bool IsEmpty(Stack *s) {
    return (s->top == 0);
}

bool IsFull(Stack *s) {
    return (s->top == s->len);
}

void Push(Stack *s, char x) {
    if (IsFull(s)) {
        printf("[Error] Stack is full\n");
        return;
    }

    ++(s->top);
    s->list[s->top] = x;
}

char Pop(Stack *s) {
    if (IsEmpty(s)) {
        printf("[Error] Stack is empty\n");
        return '\0';
    }

    --(s->top);
    return s->list[s->top + 1];
}