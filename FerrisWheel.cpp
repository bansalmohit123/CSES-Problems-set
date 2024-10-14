#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long int count=0;
 
    int i=0, j=n-1;
    while(i<=j){
        if(a[i]+a[j]<=x){
            i++;
            j--;
            count++;
        }
        else{
            j--;
            count++;
        }
    }
    cout << count << endl;



    return 0;
}