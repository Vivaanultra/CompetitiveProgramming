#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    string result = "";
    result += grid[0][0];

    // Stores valid (row, col) positions for the current step
    vector<pair<int, int>> current_positions;
    current_positions.push_back({0, 0});

    // Total steps to reach bottom-right is (n-1) moves right + (n-1) moves down
    int total_moves = 2 * n - 2;

    for (int step = 0; step < total_moves; step++) {
        char min_char = '{'; // ASCII value larger than 'Z'
        
        // 1. Find the smallest character available in the NEXT neighbors
        for (auto p : current_positions) {
            int r = p.first;
            int c = p.second;

            // Check Right neighbor
            if (c + 1 < n) min_char = min(min_char, grid[r][c + 1]);
            // Check Down neighbor
            if (r + 1 < n) min_char = min(min_char, grid[r + 1][c]);
        }

        result += min_char;

        // 2. Collect all valid next positions that have this min_char
        vector<pair<int, int>> next_candidates;
        for (auto p : current_positions) {
            int r = p.first;
            int c = p.second;

            // Try Right
            if (c + 1 < n && grid[r][c + 1] == min_char) {
                next_candidates.push_back({r, c + 1});
            }
            // Try Down
            if (r + 1 < n && grid[r + 1][c] == min_char) {
                next_candidates.push_back({r + 1, c});
            }
        }

        // 3. Remove duplicates (paths might merge)
        sort(next_candidates.begin(), next_candidates.end());
        next_candidates.erase(unique(next_candidates.begin(), next_candidates.end()), next_candidates.end());

        current_positions = next_candidates;
    }

    cout << result << endl;

    return 0;
}