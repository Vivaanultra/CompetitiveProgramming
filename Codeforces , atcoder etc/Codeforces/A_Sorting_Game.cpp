#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // Check if the string is already sorted
    bool is_sorted = true;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] > s[i+1]) {
            is_sorted = false;
            break;
        }
    }

    // If already sorted, Alice has no moves and loses.
    if (is_sorted) {
        cout << "Bob" << "\n";
        return;
    }

    // Otherwise, Alice wins in exactly 1 move.
    // Strategy: Select all characters that are not in their correct sorted positions.
    
    // 1. Count total zeros to determine the sorted state boundaries.
    int zeros_count = 0;
    for (char c : s) {
        if (c == '0') zeros_count++;
    }

    // 2. Identify indices where s[i] differs from the target sorted string.
    // The target string should have '0's at indices [0, zeros_count-1]
    // and '1's at indices [zeros_count, n-1].
    vector<int> moves;
    for (int i = 0; i < n; ++i) {
        if (i < zeros_count) {
            // Should be '0'. If it is '1', we select it.
            if (s[i] == '1') {
                moves.push_back(i + 1); // Store 1-based index
            }
        } else {
            // Should be '1'. If it is '0', we select it.
            if (s[i] == '0') {
                moves.push_back(i + 1); // Store 1-based index
            }
        }
    }

    // Output Alice's win and the move details
    cout << "Alice" << "\n";
    cout << moves.size();
    for (int idx : moves) {
        cout << " " << idx;
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}