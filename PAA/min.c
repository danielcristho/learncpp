//From PAA
#include <stdio.h>

int main() {
    int n,k;
    scanf("%d", &n);
    k=(n/5)-(((n-(n/5)*5) & 1) == 1);
    k+=(n-k*5) >> 1;
    printf("%d\n", k);
    return 0;
}