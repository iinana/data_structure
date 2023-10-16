#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/* isPalindrome */
bool isPalindrome(char *word, int len);

/* isBalanced */
bool isOpen(char c);
bool isClose(char c);
bool isPair(char open, char close);
bool isBalanced(char *word, int len);

#endif
