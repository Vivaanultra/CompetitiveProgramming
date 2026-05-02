#include <bits/stdc++.h>

using namespace std;

// Function to calculate the value of a cell at row r and column c
// r and c are 0-indexed
long long get_value(int n, int r, int c) {
    return (long long)r * n + c + 1;
}

void solve() {
    int n;
    cin >> n;

    // Special case for n=1
    if (n == 1) {
        cout << 1 << endl;
        return;
    }

    long long max_cost = 0;

    // Direction vectors for neighbors: Up, Down, Left, Right
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    // Iterate through every cell in the grid
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            
            // Start cost with the value of the cell itself
            long long current_cost = get_value(n, i, j);

            // Check all 4 potential neighbors
            for (int k = 0; k < 4; ++k) {
                int ni = i + dr[k];
                int nj = j + dc[k];

                // Verify the neighbor is within grid bounds
                if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                    current_cost += get_value(n, ni, nj);
                }
            }

            // Update maximum cost found so far
            if (current_cost > max_cost) {
                max_cost = current_cost;
            }
        }
    }

    cout << max_cost << endl;
}

int main() {
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}