#include <bits/stdc++.h>

using namespace std;

int investArr(vector<int> arr, int n) {
    int global_max = INT_MIN, local_max = 0;
    for (int i = 0; i < n; i++)
        local_max = local_max + arr[i], global_max = max(global_max, local_max), 
        local_max = max(0, local_max);

    return global_max;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, maxx = INT_MIN;
    cin>>n;
    vector<int> arr[n];
    for(int i=0; i<n; i++) {
        arr[i] = vector<int>(n, 0);
        for(int j=0; j<n; j++) cin>>arr[i][j];
    }
    for (int start = 0; start < n; start++) {
        vector<int> dimension(n, 0);
        for (int end = start; end < n; end++) {
            for (int i = 0; i < n; i++) dimension[i] += arr[i][end];
            maxx = max(investArr(dimension, n), maxx);
        }
    }
    cout<<maxx<<'\n';
}