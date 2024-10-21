#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long int> v(n);
    for(int i = 0; i < n; i++){
        v[i] = i + 1;
    }
    if(n<4&&n!=1){
        cout << "NO SOLUTION" << endl;
    } else {
        for(long long int i = 1; i < n; i += 2){
            cout << v[i] << " ";
        }
        for(long long int i = 0; i < n; i += 2){
            cout << v[i] << " ";
        }
    }
    return 0;

}