#include "main.h"

bool TwoSum(Hash **table, int n) {
    for (int i = 0; i <= n/2; i++) {
        if ((table[i]) && (table[n-i])) {
            Hash *num1 = table[i];
            Hash *num2 = table[n-i];

            while (num1) {
                while (num2) {
                    if ((num1->value + num2->value) == n) return true;
                    num2 = num2->next; 
                }
                num1 = num1->next;
            }
        }
    }
    return false;
}