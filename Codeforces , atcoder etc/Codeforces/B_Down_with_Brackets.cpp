#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); // Speed up I/O
    cin.tie(0);
    
    int t; // Number of test cases
    cin >> t;
    
    for (int test = 0; test < t; test++) {
        string s; // Balanced bracket sequence
        cin >> s;
        int n = s.size(); // Length of the string
        
        int cum = 0; // Cumulative sum
        bool can_imbalance = false; // Flag to indicate if imbalance is possible
        
        // Process each character in the string
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                cum += 1;
            } else { // s[i] == ')'
                cum -= 1;
            }
            // If cumulative sum hits 0 before the last position
            if (i < n - 1 && cum == 0) {
                can_imbalance = true;
                break; // No need to check further
            }
        }
        
        // Output result
        if (can_imbalance) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}