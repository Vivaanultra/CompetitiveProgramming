#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    // Concatenate s with itself to handle circular gaps
    string ss = s + s;
    
    int max_zeros = 0;
    int current_zeros = 0;
    
    for (char c : ss) {
        if (c == '0') {
            current_zeros++;
        } else {
            max_zeros = max(max_zeros, current_zeros);
            current_zeros = 0;
        }
    }
    // Final check in case the string ends with zeros
    max_zeros = max(max_zeros, current_zeros);
    
    // The maximum circular gap cannot exceed n-1 since there is at least one '1'
    if (max_zeros > n) max_zeros = n - 1; 

    cout << max_zeros << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}