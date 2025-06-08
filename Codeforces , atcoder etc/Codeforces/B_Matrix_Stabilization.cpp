#include <iostream>
#include <vector>
#include <algorithm> // For std::max

// Helper function to check if coordinates are within matrix bounds
// Using 0-indexed row r, col c for an n x m matrix
bool is_valid(int r, int c, int n, int m) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

// Directions for neighbors: up, down, left, right
const int DR[] = {-1, 1, 0, 0};
const int DC[] = {0, 0, -1, 1};

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<long long>> current_a(n, std::vector<long long>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> current_a[i][j];
        }
    }

    bool changed_in_iteration = true;
    while (changed_in_iteration) {
        changed_in_iteration = false;
        std::vector<std::vector<long long>> next_a = current_a; 

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                long long max_neighbor_val = 0; 
                // All a_ij >= 1. So max_neighbor_val will be >= 1 if there's any neighbor.
                // Problem constraint N*M > 1 implies every cell has at least one neighbor.
                
                // int num_actual_neighbors = 0; // Not strictly needed for logic with N*M > 1

                for (int k = 0; k < 4; ++k) { // Check all 4 directions
                    int ni = i + DR[k];
                    int nj = j + DC[k];

                    if (is_valid(ni, nj, n, m)) {
                        max_neighbor_val = std::max(max_neighbor_val, current_a[ni][nj]);
                        // num_actual_neighbors++;
                    }
                }
                
                // Based on problem constraints (N*M > 1, so every cell has neighbors),
                // max_neighbor_val will be the actual max over existing neighbors (and thus >=1).
                if (current_a[i][j] > max_neighbor_val) { // Strictly greater condition
                    next_a[i][j] = max_neighbor_val;
                    changed_in_iteration = true;
                }
                // else, next_a[i][j] remains current_a[i][j] (from the initial copy).
            }
        }
        current_a = next_a; // Update current_a to the new state for the next iteration
    }

    // Output the stabilized matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << current_a[i][j] << (j == m - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}