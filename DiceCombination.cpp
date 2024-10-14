#include<bits/stdc++.h>
using namespace std;
long long int MOD = 1e9+7;

int solve(int n , vector<long long int> &dp){
    if(n==0){
        return 1;
    }

    if(n<0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n]%MOD;
    }

    dp[n] = 0;  
    for (int i = 1; i <= 6; i++) {
        dp[n] += solve(n - i, dp)%MOD;
    }
    
    return dp[n]%MOD;

}

int main(){
    int n;
    cin >> n;
    vector<long long int> dp(n+1,-1);
    long long int ans=solve(n,dp)%MOD;
    cout << ans%MOD << endl;

}
