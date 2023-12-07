#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    long long int *fibonacci = (long long int *)malloc(sizeof(long long int) * (n+1));
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    for (int i = 2; i <= n; i++) {
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }
    
    printf("%lld", fibonacci[n]);
}
