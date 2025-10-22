#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    // Step 1: Find all possible ticks and mark the cells they cover.
    vector<vector<bool>> covered(n, vector<bool>(m, false));

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            if (grid[r][c] == '*') {
                // Measure the largest possible tick centered at (r, c)
                int d = 0;
                while (r - (d + 1) >= 0 && c - (d + 1) >= 0 && c + (d + 1) < m &&
                       grid[r - (d + 1)][c - (d + 1)] == '*' &&
                       grid[r - (d + 1)][c + (d + 1)] == '*') {
                    d++;
                }

                // If the tick is large enough, mark its cells as covered.
                if (d >= k) {
                    for (int i = 0; i <= d; ++i) {
                        covered[r - i][c - i] = true;
                        covered[r - i][c + i] = true;
                    }
                }
            }
        }
    }

    // Step 2: Verify that all stars in the original grid were covered.
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            if (grid[r][c] == '*' && !covered[r][c]) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
}

int main() {
    // It is currently Saturday, 11:57 PM in Mathura, India.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}