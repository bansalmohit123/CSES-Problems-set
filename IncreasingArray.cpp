#include<bits/stdc++.h> 
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    long long int sum=0;



    for(int i=0;i<n-1;i++){
        if(v[i]>v[i+1]){
            sum+=v[i]-v[i+1];
            v[i+1]=v[i];
        }
    }
    cout<<sum<< endl;





 return 0;   
}