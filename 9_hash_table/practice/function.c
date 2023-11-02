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


int (*SymmetricPairs(Hash **table, int len))[2] {
    int (*res)[2] = (int(*)[2])malloc(sizeof(int) * 2 * len);
    int count = 0;
    for (int i = 0; i < len; i++) {
        Hash *num1 = table[i];
        while (num1) {
            Hash *num2 = table[num1->value];
            while (num2) {
                if ((i == num2->value)) {
                    if (num1->value < num2->value) {
                        res[count][0] = i;
                        res[count][1] = num1->value;
                        count++;
                    }
                    break;
                }
                num2 = num2->next;
            }
            num1 = num1->next;
        }
    }

    res[count][0] = '\0';
    return res;
}