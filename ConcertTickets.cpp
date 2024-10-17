#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    multiset<long long int> v;
    vector<long long int> t(m);
    

    for (int i = 0; i < n; i++) {
        long long int h;
        cin >> h;
        v.insert(h);
    }
    

    for (int i = 0; i < m; i++) {
        cin >> t[i];
    }
    
    for (int i = 0; i < m; i++) {
        long long int x = t[i];
        

        auto it = v.upper_bound(x);
        
        if (it == v.begin()) {
        
            cout << -1 << endl;
        } else {
           
            it--;
            cout << *it << endl;
            v.erase(it); 
        }
    }

    return 0;
}
