#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n;
    cin >> n;
    for (long long int i = 1; i <= n; i++) {
        long long total = i * i * (i * i - 1) / 2;
        long long attack = 4 * (i - 1) * (i - 2);
        cout << total - attack << endl;
    }


}