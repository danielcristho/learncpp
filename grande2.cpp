#include <bits/stdc++.h>
using namespace std;

int sum(vector<int>build) {
    int joon, grande, value, area=0;;
    for (int i=0; i<build.size(); i++) {
        joon=build[i];
        for (int j=i; j<build.size(); j++) {
            joon = min(joon, build[j]);
            grande = j-i+1;
            value = grande * joon;
            area = max(value,area);
        }
    }   return area;

}

int main() {
    int square, n, h;
    while(cin >> n) { vector<int>build;
        for (int i=0; i<n; i++) {
            cin >> h;
            build.push_back(h);
        }   square=sum(build);
        cout << square << endl;
        }
}