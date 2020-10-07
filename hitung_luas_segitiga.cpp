# include <iostream>
# include <iomanip>

using namespace std;
int main()
{
    int A, T;
    float luas;

    cin>>A>>T;
    luas = A*T*0.5;
    cout<<setprecision(2)<<fixed;
    cout<<luas<<endl;

    
    return 0;
}