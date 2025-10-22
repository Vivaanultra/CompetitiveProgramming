#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> grid(n);
    vector<pair<int, int>> stars;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '*') {
                stars.push_back({i, j});
            }
        }
    }

    int r1 = stars[0].first;
    int c1 = stars[0].second;
    int r2 = stars[1].first;
    int c2 = stars[1].second;

    if (r1 != r2 && c1 != c2) {
        // Case 1: Stars form a diagonal
        grid[r1][c2] = '*';
        grid[r2][c1] = '*';
    } else if (r1 == r2) {
        // Case 2: Stars are in the same row
        int new_r = (r1 > 0) ? r1 - 1 : r1 + 1;
        grid[new_r][c1] = '*';
        grid[new_r][c2] = '*';
    } else { // c1 == c2
        // Case 3: Stars are in the same column
        int new_c = (c1 > 0) ? c1 - 1 : c1 + 1;
        grid[r1][new_c] = '*';
        grid[r2][new_c] = '*';
    }

    for (int i = 0; i < n; ++i) {
        cout << grid[i] << endl;
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