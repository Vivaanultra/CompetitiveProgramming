#include <bits/stdc++.h>

using namespace std;

// Helper function to find the minimum deletions for a given suffix
int solve_for_suffix(string s, string suffix) {
    int n = s.length();
    int suffix_ptr = 1; // Start with the last char of the suffix (e.g., '5' of "25")
    int deletions = 0;

    // Find the last digit of the suffix
    int i = n - 1;
    while (i >= 0) {
        if (s[i] == suffix[suffix_ptr]) {
            suffix_ptr--;
            break; 
        }
        deletions++;
        i--;
    }

    // If the last digit was not found
    if (i < 0) return 1e9;

    // Find the first digit of the suffix
    i--; // Move to the character before the one we just found
    while (i >= 0) {
        if (s[i] == suffix[suffix_ptr]) {
            suffix_ptr--;
            break;
        }
        deletions++;
        i--;
    }
    
    // If the first digit was not found
    if (suffix_ptr >= 0) return 1e9;

    return deletions;
}

void solve() {
    string n_str;
    cin >> n_str;

    int ans = 1e9; // Initialize with a large value

    ans = min(ans, solve_for_suffix(n_str, "00"));
    ans = min(ans, solve_for_suffix(n_str, "25"));
    ans = min(ans, solve_for_suffix(n_str, "50"));
    ans = min(ans, solve_for_suffix(n_str, "75"));
    
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}