#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t; // Number of test cases
    for (int test = 0; test < t; test++) {
        int n, m;
        cin >> n >> m; // Grid dimensions
        vector<string> grid(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i]; // Read the grid
        }

        bool changed = true;
        while (changed) {
            changed = false;
            vector<pair<int, int>> to_remove;

            // Scan the grid for removable balls
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == '1') {
                        bool can_remove = false;

                        // Check row: all positions to the left must be 1
                        bool all_left = true;
                        for (int k = 0; k < j; k++) {
                            if (grid[i][k] != '1') {
                                all_left = false;
                                break;
                            }
                        }
                        if (all_left) can_remove = true;

                        // Check column: all positions above must be 1
                        bool all_above = true;
                        for (int k = 0; k < i; k++) {
                            if (grid[k][j] != '1') {
                                all_above = false;
                                break;
                            }
                        }
                        if (all_above) can_remove = true;

                        if (can_remove) {
                            to_remove.push_back({i, j});
                        }
                    }
                }
            }

            // Remove all identified balls
            for (auto [i, j] : to_remove) {
                grid[i][j] = '0';
                changed = true;
            }
        }

        // Check if the grid is empty
        bool all_zero = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    all_zero = false;
                    break;
                }
            }
            if (!all_zero) break;
        }

        // Output result
        cout << (all_zero ? "YES" : "NO") << "\n";
    }
    return 0;
}