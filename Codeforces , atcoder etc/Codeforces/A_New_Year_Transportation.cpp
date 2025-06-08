#include <bits/stdc++.h> // Includes all standard libraries
using namespace std; // Using standard namespace

int main() {
    // Optimize C++ standard streams for faster I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; // Number of cells
    int t; // Target cell
    cin >> n >> t;

    // There are n-1 portals. a_i is the value for the portal starting at cell i (1-indexed).
    // We'll store these n-1 values in a 0-indexed vector `portals_values`.
    // portals_values[0] will store a_1, portals_values[1] will store a_2, and so on.
    // So, portals_values[k] stores a_{k+1}.
    vector<int> portals_values(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> portals_values[i];
    }

    int current_cell = 1; // We start at cell 1.

    // Simulate the movement.
    // Continue as long as:
    // 1. We haven't reached or passed the target cell t (current_cell < t).
    // 2. We are on a cell that has an outgoing portal. Portals are defined for cells 1 to n-1.
    //    So, current_cell must be less than n (current_cell <= n-1) to make a move.
    //    If current_cell is n-1, it's the last cell with a portal.
    //    If current_cell becomes n, the condition (current_cell < n) becomes false, and the loop stops.
    while (current_cell < t && current_cell < n) {
        // If we are at current_cell (1-indexed), we use the portal starting from current_cell.
        // The value a_{current_cell} is stored at index (current_cell - 1)
        // in our 0-indexed portals_values vector.
        current_cell += portals_values[current_cell - 1];
    }

    // After the loop, check if we landed exactly on cell t.
    if (current_cell == t) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}