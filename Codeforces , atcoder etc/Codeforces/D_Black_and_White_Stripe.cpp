#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Using competitive programming practices
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int current_white_cells = 0;

    // 1. Calculate the number of white cells in the first window of size k
    for (int i = 0; i < k; ++i) {
        if (s[i] == 'W') {
            current_white_cells++;
        }
    }

    // This is our initial best answer
    int min_white_cells = current_white_cells;

    // 2. Slide the window from left to right
    for (int i = k; i < n; ++i) {
        // Add the new element entering the window from the right
        if (s[i] == 'W') {
            current_white_cells++;
        }
        // Remove the old element leaving the window from the left
        if (s[i - k] == 'W') {
            current_white_cells--;
        }

        // 3. Update the overall minimum
        if (current_white_cells < min_white_cells) {
            min_white_cells = current_white_cells;
        }
    }

    cout << min_white_cells << endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}