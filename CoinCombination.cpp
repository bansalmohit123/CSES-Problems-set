#include<bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
int  main() {
    int  n, x;
    cin >> n >> x;
    vector<int > coins(n);
    vector<long long int > dp(x + 1, 0);
    for (long long int  i = 0; i < n; i++) {
        cin >> coins[i];
    }
    for(long long int i = 0; i <= x; i++) {
        if(i == 0) {
            dp[i] = 1;
        } else {
            for(int j = 0; j < n; j++) {
                if(i - coins[j] >= 0) {
                    dp[i] += dp[i - coins[j]];
                    dp[i] %= mod;
                }
            }
        }
    }
    
    cout << dp[x]<< endl;
}