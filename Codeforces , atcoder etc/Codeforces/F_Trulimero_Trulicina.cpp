#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> grid(n, vector<int>(m));

    if (n % k != 0) {
        // Plan A: Column-by-column fill is safe.
        int current_color = 0;
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                grid[i][j] = current_color;
                current_color = (current_color + 1) % k;
            }
        }
    } else if (m % k != 0) {
        // Plan B: Row-by-row fill is safe.
        int current_color = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                grid[i][j] = current_color;
                current_color = (current_color + 1) % k;
            }
        }
    } else {
        // Plan C: Both n and m are multiples of k. Use a shifted pattern.
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                grid[i][j] = (i + j) % k;
            }
        }
    }

    // Print the resulting grid (converting colors from 0-based to 1-based).
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << grid[i][j] + 1 << (j == m - 1 ? "" : " ");
        }
        cout << "\n";
    }
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