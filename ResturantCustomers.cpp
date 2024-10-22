#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, 1));
        v.push_back(make_pair(b, -1));
    }
    sort(v.begin(), v.end());
    int ans = 0;
    int count = 0;
    for(int i = 0; i < v.size(); i++){
        count += v[i].second;
        ans = max(ans, count);
    }
    cout << ans << endl;
}