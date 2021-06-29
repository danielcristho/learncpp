#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
int arr[1000010];
int zydn, baris;

int main() {
    memset(arr, 0, sizeof(arr));
    arr[0] = 11; arr[1] = 15;

    for (int i=2; i < 11; i++) arr[i] = (arr[i-1]+arr[i-2]) % mod;
    for (int i=11; i < 15; i++) arr[i] = (arr[i-11]+arr[i-2]) % mod;
    for (int i=15; i < 1000000; i++) arr[i] =(arr[i-11]+arr[i-15]) % mod;
        scanf("%d", &zydn);
    for (int i=0; i < zydn; i++) {

        scanf("%d", &baris);
        printf("%d\n", arr[baris]);
    }
    return 0;    
}


