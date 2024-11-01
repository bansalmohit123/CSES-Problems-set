#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
int solve(int i ,int j,int n , vector<vector<char>> &a ,vector<vector<int>> &dp){
    if(i>=n || j>=n || a[i][j]=='*'){
        return 0;
    }
    if(i==n-1 && j==n-1){
        return 1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=0;
    ans=(ans+solve(i+1,j,n,a,dp))%mod;
    ans=(ans+solve(i,j+1,n,a,dp))%mod;
    return dp[i][j]=ans%mod;

}
int main(){
    int n;
    cin >> n;
    vector<vector<char>> a(n, vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));
    int ans=solve(0,0,n,a,dp);
    cout << ans << endl;

}