#include <iostream>
#include <vector>
#include <algorithm>

// Use standard namespace for competitive programming
using namespace std;

// Recursive DFS function to find the volume of a lake starting from cell (r, c)
// It explores all 4-directionally connected cells with water.
long long dfs(int r, int c, int n, int m, vector<vector<int>>& grid) {
    // Base case: check for out-of-bounds or a cell with no water (or already visited).
    // A cell is considered visited if its value is set to 0.
    if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == 0) {
        return 0;
    }

    // Get the volume of the current cell.
    long long current_cell_volume = grid[r][c];

    // Mark the current cell as visited by setting its depth to 0.
    // This prevents cycles and recounting it in other paths.
    grid[r][c] = 0;

    // Recursively call DFS for all 4 neighbors and add their volumes.
    long long total_volume = current_cell_volume;
    total_volume += dfs(r + 1, c, n, m, grid); // Down
    total_volume += dfs(r - 1, c, n, m, grid); // Up
    total_volume += dfs(r, c + 1, n, m, grid); // Right
    total_volume += dfs(r, c - 1, n, m, grid); // Left

    return total_volume;
}

// Function to solve a single test case
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    long long max_volume = 0;

    // Iterate through each cell of the grid
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // If a cell has water (value > 0), it could be part of a new lake.
            // The check a[i][j] > 0 also ensures we don't start a DFS from a visited cell.
            if (a[i][j] > 0) {
                // Calculate the volume of the lake connected to this cell
                long long current_lake_volume = dfs(i, j, n, m, a);
                // Update the overall maximum volume found
                max_volume = max(max_volume, current_lake_volume);
            }
        }
    }

    cout << max_volume << endl;
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}