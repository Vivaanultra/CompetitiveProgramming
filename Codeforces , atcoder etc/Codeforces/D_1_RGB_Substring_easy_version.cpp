#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int min_total_changes = INT_MAX;
    string base_pattern = "RGB";

    // Loop through the 3 possible starting patterns (0='R', 1='G', 2='B')
    for (int start_offset = 0; start_offset < 3; ++start_offset) {
        // Slide a window of size k across the string
        for (int i = 0; i <= n - k; ++i) {
            int current_changes = 0;
            // Check the current window
            for (int j = 0; j < k; ++j) {
                // The character in the string is s[i+j]
                // The target character is determined by its position in the pattern
                char target_char = base_pattern[(j + start_offset) % 3];
                if (s[i + j] != target_char) {
                    current_changes++;
                }
            }
            min_total_changes = min(min_total_changes, current_changes);
        }
    }

    cout << min_total_changes << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}