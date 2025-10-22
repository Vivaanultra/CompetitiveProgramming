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
        int current_changes = 0;

        // First, calculate the cost for the initial window (from index 0 to k-1)
        for (int i = 0; i < k; ++i) {
            if (s[i] != base_pattern[(i + start_offset) % 3]) {
                current_changes++;
            }
        }
        min_total_changes = min(min_total_changes, current_changes);

        // Now, slide the window from the 1st position to the end
        for (int i = 1; i <= n - k; ++i) {
            // O(1) update for the sliding window
            
            // 1. Subtract the cost of the character that is leaving the window (at index i-1)
            if (s[i - 1] != base_pattern[((i - 1) + start_offset) % 3]) {
                current_changes--;
            }

            // 2. Add the cost of the character that is entering the window (at index i+k-1)
            if (s[i + k - 1] != base_pattern[((i + k - 1) + start_offset) % 3]) {
                current_changes++;
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