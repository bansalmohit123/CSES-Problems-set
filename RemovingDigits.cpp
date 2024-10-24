#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n){
    vector<int> digits;
    while (n>0)
    {
        digits.push_back(n%10);
        n/=10;
    }
    return digits;
    
}

int main(){
    int n;
    cin >> n;
    int steps = 0;
    while(n>0){
    vector<int> digits= solve(n);
    int maximum = *max_element(digits.begin(), digits.end());
    n-=maximum;
    steps++;
    }
    cout << steps << endl;
}