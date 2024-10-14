#include<bits/stdc++.h>
using namespace std;


int main(){
    string s;
    cin >> s;
    long long int count = 1;
    long long int max=1;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1]){
            count++;
            if(count>max){
                max = count;
            }
        }
        else{
            count=1;
        }
    }
    if(count>max){
        max = count;
    }
    cout << max << endl;
    return 0;
}
