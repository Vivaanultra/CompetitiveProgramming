#include <iostream>
#include <string>
#include <cctype>

// Using a standard competitive programming setup
#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Read the input strings S and T
    string s, t;
    cin >> s >> t;

    // Iterate through the string S starting from the second character (index 1)
    for (int i = 1; i < s.length(); ++i) {
        // Check if the current character s[i] is an uppercase letter
        if (isupper(s[i])) {
            // If it is uppercase, check if the preceding character s[i-1] is present in string T.
            // The `find` method returns string::npos if the character is not found.
            if (t.find(s[i - 1]) == string::npos) {
                // If the preceding character is not in T, the condition is not met.
                cout << "No" << endl;
                return; // Exit since we found a violation
            }
        }
    }

    // If the loop completes without finding any violations, the condition is satisfied.
    cout << "Yes" << endl;
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}