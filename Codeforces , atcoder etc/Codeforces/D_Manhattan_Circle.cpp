#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

// Using competitive programming practices for conciseness
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    // Vectors to store the count of '#' for each row and column
    vector<int> row_counts(n, 0);
    vector<int> col_counts(m, 0);

    // Read the grid and populate the counts
    for (int i = 0; i < n; ++i) {
        string row_str;
        cin >> row_str;
        for (int j = 0; j < m; ++j) {
            if (row_str[j] == '#') {
                row_counts[i]++;
                col_counts[j]++;
            }
        }
    }

    // Find the iterator to the maximum element in row_counts
    auto max_row_it = max_element(row_counts.begin(), row_counts.end());
    // Calculate the 1-based index of the center row
    int center_r = distance(row_counts.begin(), max_row_it) + 1;

    // Find the iterator to the maximum element in col_counts
    auto max_col_it = max_element(col_counts.begin(), col_counts.end());
    // Calculate the 1-based index of the center column
    int center_c = distance(col_counts.begin(), max_col_it) + 1;

    cout << center_r << " " << center_c << endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve();
    }

    return 0;
}