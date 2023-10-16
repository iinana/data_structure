#include "main.h"

bool isPalindrome(char *word, int len) {
    int i = 0, j = len-1;
    int mid = (i + j) / 2;

    while (word[i] == word[j]) {
        if (i == mid) return true;
        i++;
        j--;
    }
    return false;
}