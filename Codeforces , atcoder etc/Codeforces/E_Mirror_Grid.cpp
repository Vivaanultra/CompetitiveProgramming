#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    long long total_flips = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (visited[i][j]) {
                continue;
            }

            int r1 = i, c1 = j;
            int r2 = j, c2 = n - 1 - i;
            int r3 = n - 1 - i, c3 = n - 1 - j;
            int r4 = n - 1 - j, c4 = i;

            int ones = (grid[r1][c1] - '0') +
                       (grid[r2][c2] - '0') +
                       (grid[r3][c3] - '0') +
                       (grid[r4][c4] - '0');

            total_flips += min(ones, 4 - ones);

            visited[r1][c1] = true;
            visited[r2][c2] = true;
            visited[r3][c3] = true;
            visited[r4][c4] = true;
        }
    }

    cout << total_flips << "\n";
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