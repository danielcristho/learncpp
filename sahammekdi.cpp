    #include <bits/stdc++.h>
     
    using namespace std;
     
    int main(){
        int mekdi, saham;
        while(scanf("%d %d", &mekdi, &saham) == 2)
        {
            if(mekdi == 0) break;
            int arr[100], A, B;
            char Z;
            for(int i = 0; i < mekdi; i++)
            {
                cin >> A >> Z >> B;
                arr[i] = A*100 + B;
            }
            if(arr[saham-1] > 5000){
                cout << "100.00\n";
                continue;
            }
            int dp[10001] = {0};
            int last = 10000-arr[saham-1];
            dp[0] = 1;
            for(int i = 0; i < mekdi; i++)
                {
                if(i == saham-1) 
                continue;
                for(int j = last-arr[i]; j >=0; j--)
                {
                    if(dp[j] == 1)
                        dp[j+arr[i]] = 1;
                }
            }
            last = 5001-arr[saham-1];
            while(dp[last]==0) last++;
            printf("%.2lf\n", arr[saham-1]*100.0/(last +arr[saham-1])*1.0);
        }
    }