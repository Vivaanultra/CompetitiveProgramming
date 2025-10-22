#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        long long total = 1LL * n * n;
        if (k == total - 1) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        // We'll build row by row
        // Place 'U' for the first k cells in row-major order
        vector<string> grid(n, string(n, '?'));
        long long rem = k;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rem > 0) {
                    grid[i][j] = 'U';
                    --rem;
                }
            }
        }
        // Fill cells that are not 'U'
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '?') {
                    if (i != n - 1) grid[i][j] = 'D';
                }
            }
        }
        // Handle last row:
        // If some cells in last row are still '?', put first such as 'R' and remaining to its right 'L'.
        // If none (i.e., all are 'U'), nothing to change.
        int first_nonU = -1;
        for (int j = 0; j < n; ++j) {
            if (grid[n-1][j] == '?') { first_nonU = j; break; }
        }
        if (first_nonU == -1) {
            // last row fully U (possible when k == n*n)
            // nothing to change
        } else {
            // put R at first_nonU, and L at positions > first_nonU
            grid[n-1][first_nonU] = 'R';
            for (int j = first_nonU + 1; j < n; ++j) {
                grid[n-1][j] = 'L';
            }
        }
        // For safety (shouldn't be any remaining '?'), set them to 'L' (fallback)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == '?') grid[i][j] = 'L';
        
        // Output
        for (int i = 0; i < n; ++i)
            cout << grid[i] << '\n';
    }
    return 0;
}
