#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Create a vector of strings to store the board state.
    vector<string> board(8);
    
    // Read the entire 8x8 board.
    // The empty line before the test case is automatically skipped by cin.
    for (int i = 0; i < 8; ++i) {
        cin >> board[i];
    }

    // Iterate through the inner part of the board (rows 2-7, columns 2-7).
    // In 0-based indexing, this corresponds to indices 1 to 6.
    for (int i = 1; i < 7; ++i) {
        for (int j = 1; j < 7; ++j) {
            // Check if the four diagonal neighbors are attacked.
            if (board[i - 1][j - 1] == '#' && 
                board[i - 1][j + 1] == '#' &&
                board[i + 1][j - 1] == '#' && 
                board[i + 1][j + 1] == '#') {
                
                // If they are, the current cell (i, j) is the bishop.
                // Output the 1-based coordinates.
                cout << i + 1 << " " << j + 1 << endl;
                return; // Exit after finding the bishop for this test case.
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}