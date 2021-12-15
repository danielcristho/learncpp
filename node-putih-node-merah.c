#include <stdio.h>
#include <string.h>
#include <limits.h>

void solve() {
    int n;
    scanf("%d", &n);
    int arr[n + 1];
    memset(arr, 0, (n+1)*sizeof(int));

    while(1) {
        int a, b;
        if (scanf("%d %d\n", &a, &b)) {
            arr[a]++; arr[b]++;
        } else {
            break;
        }
    }

    int i = 1, min = INT_MAX, max = INT_MIN;
    for (; i <= n; i++) {
        if (arr[i] <= min) {
            min = i;
        }
        if (arr[i] > max) {
            max = i;
        }
    }

    printf("%d itu si Node Putih\n", max);
    printf("%d itu si Node Merah\n", min);
}

int main() {
    solve();
    return 0;
}
