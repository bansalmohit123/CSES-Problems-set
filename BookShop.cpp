#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,x;
    cin>>n>>x;
    vector<int>h(n);
    vector<int>s(n);
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
    }
       for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    vector<vector<int>>dp(n+1,vector<int>(x+1,0));
     for (int i = 0; i <n; i++) { 

        for (int j = x; j >= 0; j--) { 
            int take = 0, notTake = 0;

            
            if (j - h[i - 1] >= 0) {
                take = s[i] + dp[i ][j - h[i]]; 
            }
            notTake = dp[i][j]; 

            dp[i][j] = max(take, notTake);
        }
    }
     cout << dp[n-1][x] << endl;
    return 0;
}