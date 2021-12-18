#include<bits/stdc++.h> 
#define ll long long 
using namespace std; 
 
double approach1(int x) 
{ 
    double sum = 1, temp = 1; 
    for(int i = 0; i < 20; i++) 
    { 
        temp = temp*(-1)*x/(i+1); 
        sum += temp; 
    } 
    return sum; 
} 
double approach2(int x) 
{ 
    double sum = 1, temp = 1; 
    for(int i = 0; i < 20; i++) 
    { 
        temp = temp*x/(i+1); 
        sum += temp; 
    } 
    return 1/sum; 
} 
double error(double x) 
{ 
    return abs((6.737947e-03-x)*100.0/6.737947e-03); 
} 
 
int main() 
{ 
    int x = 35; 
    double x1 = approach1(x); 
    double x2 = approach2(x); 
    cout << "%error approach1: " << error(x1) << "\n"; 
    cout << "%error approach2: " << error(x2) << "\n"; 
}    