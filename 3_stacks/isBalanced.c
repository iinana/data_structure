#include "main.h"
#include "stack.h"

bool isOpen(char c) {
    return ((c == '(') || (c == '{') || (c == '['));
}

bool isClose(char c) {
    return ((c == ')') || (c == '}') || (c == ']'));
}

bool isPair(char open, char close)
{
    if ((open == '(') && (close == ')')) return true;
    else if ((open == '{') && (close == '}')) return true;
    else if ((open == '[') && (close == ']')) return true;
    else return false;
}

bool isBalanced(char *word, int len){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->list = (char *)malloc(sizeof(char) * len);
    s->len = len;
    s->top = 0;
    
    for (int i = 0; i < len; i++) {
        if (isOpen(word[i])) Push(s, word[i]); 
        else if (isClose(word[i])) {
            if (isPair(s->list[s->top], word[i])) Pop(s);
            else return false;
        }
    }
    if (IsEmpty(s)) return true;
    else return false;
}