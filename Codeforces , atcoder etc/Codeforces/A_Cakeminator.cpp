#include <iostream>
#include <vector>
#include <string>

int main() {
    // Optimize C++ input/output operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int r, c;
    std::cin >> r >> c;

    // Store the cake grid
    std::vector<std::string> cake(r);
    
    // Use boolean vectors to track which rows and columns contain an 'S'
    std::vector<bool> row_has_S(r, false);
    std::vector<bool> col_has_S(c, false);

    // Read the grid and mark the "unsafe" rows and columns
    for (int i = 0; i < r; ++i) {
        std::cin >> cake[i];
        for (int j = 0; j < c; ++j) {
            if (cake[i][j] == 'S') {
                row_has_S[i] = true;
                col_has_S[j] = true;
            }
        }
    }

    // Count the number of rows that are "safe" (no 'S')
    int safe_rows = 0;
    for (int i = 0; i < r; ++i) {
        if (!row_has_S[i]) {
            safe_rows++;
        }
    }

    // Count the number of columns that are "safe" (no 'S')
    int safe_cols = 0;
    for (int j = 0; j < c; ++j) {
        if (!col_has_S[j]) {
            safe_cols++;
        }
    }

    int total_eaten = (safe_rows * c) + (safe_cols * r) - (safe_rows * safe_cols);

    std::cout << total_eaten << "\n";

    return 0;
}