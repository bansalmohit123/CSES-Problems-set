#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int solve(int i, int n, int m, vector<int>& arr, vector<vector<int>>& dp, int prev) {
    if (i >= n) return 1;
    if (dp[i][prev] != -1) return dp[i][prev];

    int ways = 0;

    if (arr[i] == 0) {
        for (int k = 1; k <= m; k++) {
            if (i == 0 || abs(k - prev) <= 1) {
                ways = (ways + solve(i + 1, n, m, arr, dp, k)) % MOD;
            }
        }
    } else {
        if (i == 0 || abs(arr[i] - prev) <= 1) {
            ways = (ways + solve(i + 1, n, m, arr, dp, arr[i])) % MOD;
        }
    }

    return dp[i][prev] = ways;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> dp(n, vector<int>(m + 1, -1));
    int ans = solve(0, n, m, arr, dp, 0);
    cout << ans << endl;
    return 0;
}
