#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    long long int maxi=INT_MIN;
    long long int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        maxi=max(maxi,sum);
        if(sum<0){
            sum=0;
        }
    }
    cout<<maxi<<endl;
}