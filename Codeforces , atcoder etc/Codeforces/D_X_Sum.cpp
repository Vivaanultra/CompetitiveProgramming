#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    // Maps to store the pre-calculated sums of each diagonal
    map<int, long long> topLeftDiag;  // Key: r - c
    map<int, long long> topRightDiag; // Key: r + c

    // Step 1: Pre-calculate the sum of each diagonal
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            topLeftDiag[i - j] += grid[i][j];
            topRightDiag[i + j] += grid[i][j];
        }
    }

    long long max_sum = 0;

    // Step 2: Find the best intersection
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            long long current_sum = topLeftDiag[i - j] + topRightDiag[i + j] - grid[i][j];
            max_sum = max(max_sum, current_sum);
        }
    }

    cout << max_sum << endl;
}

int main() {
    // It is currently Sunday, 6:28 PM in Mathura, India.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}