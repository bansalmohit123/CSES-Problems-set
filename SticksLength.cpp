#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    long long int ans = 0;
    long long int mid=n/2;
    for(int i = 0; i < n; i++){
        ans += abs(v[i] - v[mid]);
    }
    cout << ans << endl;
    
}