#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){
        long long int x, y;
        cin >> x >> y;
        long long int z = max(x, y);
        long long int z2 = z * z;
        long long int ans = 0;
        if(z % 2 == 0){
            if(z == x){
                ans = z2 - y + 1;
            } else {
                ans = z2 - 2 * z + x + 1;
            }
        } else {
            if(z == y){
                ans = z2 - x + 1;
            } else {
                ans = z2 - 2 * z + y + 1;
            }
        }
        cout << ans << endl;
        

    }
}