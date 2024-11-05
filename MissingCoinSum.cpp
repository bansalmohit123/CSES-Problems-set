#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> coins(n);

    // Input the coin values
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // Sort the coin values
    sort(coins.begin(), coins.end());

    long long smallest_unmakeable_sum = 1;
    for (int i = 0; i < n; i++) {
    
        if (coins[i] > smallest_unmakeable_sum) {
            break;
        }
        
        smallest_unmakeable_sum += coins[i];
    }

  
    cout << smallest_unmakeable_sum << endl;

    return 0;
}
