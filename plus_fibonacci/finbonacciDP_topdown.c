#include <stdio.h>

int res[90];

int fibo(int n) {
    if (n <= 1) return n;
    else {
        if (res[n] > 0) return res[n];
        else {
            res[n] = fibo(n-1) + fibo(n-2);
            return res[n];
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d", fibo(n));
}