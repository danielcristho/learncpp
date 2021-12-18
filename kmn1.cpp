#include<bits/stdc++.h> 
#define ll long long 
using namespace std; 
 
int main() 
{ 
    float x; int n; 
    cin >> x >> n; 
    x = x * M_PI / 180.0; 
    float sum = 1, temp=1, error; 
    for(int i = 0; i < n; i++) 
    { 
        error = (cos(x)-sum)*100/cos(x); 
        cout<< left  
            << setw(8) << "iterasi "<< i+1 << ": " << setw(10) << sum 
            << left 
            << setw(6) <<"%error " << i+1 << ": " << abs(error) << "\n";  
        temp = temp*(-1)*x*x/(2*(i+1)*(2*(i+1)-1)); 
        sum += temp; 
    } 
}