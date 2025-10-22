#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

// Use competitive programming standards for brevity
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Checks if it's possible to make the maximum element in the matrix <= x.
 *
 * @param x The target maximum value.
 * @param n The number of rows.
 * @param m The number of columns.
 * @param a The matrix.
 * @return True if possible, false otherwise.
 */
bool check(long long x, int n, int m, const vector<vector<int>>& a) {
    vector<pair<int, int>> needs_help;

    // 1. Find all problematic cells.
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // If any cell is > x+1, it's impossible to reduce it enough.
            if (a[i][j] > x + 1) {
                return false;
            }
            // If a cell is > x, it must be on the chosen cross.
            if (a[i][j] > x) {
                needs_help.push_back({i, j});
            }
        }
    }

    // If no cells need help, x is achievable.
    if (needs_help.empty()) {
        return true;
    }

    // 2. Check if a single cross can cover all 'needs_help' cells.
    // We pick the first problematic cell as a pivot. Any valid cross must cover it.
    int r_pivot = needs_help[0].first;
    int c_pivot = needs_help[0].second;

    // Possibility A: The chosen row is r_pivot.
    // Check if all other needy cells lie on this row OR on a single other column.
    set<int> needed_cols;
    for (const auto& cell : needs_help) {
        if (cell.first != r_pivot) {
            needed_cols.insert(cell.second);
        }
    }
    if (needed_cols.size() <= 1) {
        return true;
    }

    // Possibility B: The chosen column is c_pivot.
    // Check if all other needy cells lie on this column OR on a single other row.
    set<int> needed_rows;
    for (const auto& cell : needs_help) {
        if (cell.second != c_pivot) {
            needed_rows.insert(cell.first);
        }
    }
    if (needed_rows.size() <= 1) {
        return true;
    }

    // If neither a cross through r_pivot nor c_pivot works, it's impossible.
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    // Binary search for the minimum possible maximum value.
    long long low = 0, high = 101, ans = 101;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid, n, m, a)) {
            ans = mid;
            high = mid - 1; // Try for an even smaller max
        } else {
            low = mid + 1; // Target max is too small
        }
    }
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