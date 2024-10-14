#include <bits/stdc++.h>
using namespace std;

bool canFormPalindrome(int m, const vector<int>& freq, int n) {
    int odd_count = 0;
    for (int count : freq) {
        if (count % 2 == 1) {
            odd_count++;
        }
    }
    
    return odd_count <= (n / m);
}

string constructPalindromeSequence(int m, vector<int>& freq, int n) {
    int half_m = m / 2; 
    vector<string> palin(n / m, string(m, ' ')); 
    int idx = 0;


    for (int i = 0; i < 26; ++i) {
        char c = 'a' + i;
        while (freq[i] >= 2 && idx < n / m) {
            palin[idx][0] = c;          
            palin[idx][m - 1] = c;      
            freq[i] -= 2;               
            idx++;
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (freq[i] > 0 && m % 2 == 1 && idx > 0) {
            palin[idx - 1][half_m] = 'a' + i; 
            break;
        }
    }

    string result = "";
    for (const string& p : palin) {
        result += p; 
    }

    return result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        bool found = false;
        string palindrome_seq;

       
        for (int m = 2; m <= n; ++m) {
            if (n % m == 0 && canFormPalindrome(m, freq, n)) {
                palindrome_seq = constructPalindromeSequence(m, freq, n);
                found = true;
                cout << m << endl; 
                cout << palindrome_seq << endl; 
                break;
            }
        }

        if (!found) {
            cout << -1 << endl; 
        }
    }

    return 0;
}
