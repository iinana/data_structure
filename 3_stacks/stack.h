#ifndef STACK_H
#define STACK_H

typedef struct STACK {
    int top;
    int len;
    char *list;
} Stack;

bool IsEmpty(Stack *s);
bool IsFull(Stack *s);
void Push(Stack *s, char x);
char Pop(Stack *s);

#endif