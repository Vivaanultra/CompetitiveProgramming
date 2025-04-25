// Includes almost all standard C++ libraries.
// This is common in competitive programming for convenience, avoiding the need
// to include many individual headers like <vector>, <iostream>, <set>, <algorithm>, etc.
#include <bits/stdc++.h>

// This line brings all names from the standard namespace (like cout, cin, vector, max, etc.)
// into the current scope, so we don't have to write std:: before them.
using namespace std;

int main() {
    // --- Input/Output Optimization ---
    // These lines are standard C++ optimizations for faster input/output operations,
    // often crucial in competitive programming to pass time limits.
    // ios::sync_with_stdio(false) disables synchronization between C-style I/O (like printf/scanf)
    // and C++ I/O streams (like cin/cout).
    ios::sync_with_stdio(false);
    // cin.tie(nullptr) unties cin from cout, meaning the program won't automatically flush
    // the output buffer (cout) every time an input operation (cin) is performed.
    cin.tie(nullptr);

    // --- Variable Declarations and Initial Input ---
    int N; // Number of rows in the grid
    int M; // Number of columns in the grid
    int K; // Number of distinct fruit types (numbered 1 to K)
    // Read the grid dimensions and number of fruit types from standard input.
    cin >> N >> M >> K;

    // --- Grid Representation ---
    // Instead of a 2D vector (vector<vector<int>>), this solution uses a 1D vector
    // to represent the grid. This is called "flattening" the grid.
    // The size is N * M, the total number of cells.
    // To access the element corresponding to row `i` and column `j` (0-based),
    // the index `idx = i * M + j` is used.
    vector<int> grid(N * M);

    // --- Core Optimization Data Structures ---
    // The key insight for optimizing Type 2 queries (max Manhattan distance) is based on
    // the property: Manhattan distance |i1 - i2| + |j1 - j2| is equal to
    // max( |(i1+j1) - (i2+j2)| , |(i1-j1) - (i2-j2)| ).
    // This means the maximum Manhattan distance between two points corresponds to the
    // maximum difference between their (i+j) values OR the maximum difference between
    // their (i-j) values.

    // To efficiently find these maximum differences, we maintain two data structures
    // for *each* fruit type:
    // S1: Stores the value (i+j) for every cell (i, j) containing a specific fruit.
    // S2: Stores the value (i-j) for every cell (i, j) containing a specific fruit.

    // We use a vector of multisets. The outer vector is indexed by fruit type (1 to K).
    // The inner `multiset<int>` stores the transformed coordinate values (i+j or i-j).
    // `multiset` is chosen because:
    //   1. It automatically keeps the elements sorted, allowing O(log n) insertion/deletion
    //      and O(1) access to the minimum and maximum elements.
    //   2. It allows duplicate values, which is necessary because multiple different cells
    //      (i, j) might result in the same (i+j) or (i-j) value.
    // The size is K+1 so we can use 1-based indexing for fruit types (index f corresponds to fruit f).
    vector<multiset<int>> S1(K + 1), S2(K + 1);

    // --- Initial Grid Population ---
    // Loop through each row `i` from 0 to N-1.
    for (int i = 0; i < N; i++) {
        // Loop through each column `j` from 0 to M-1.
        for (int j = 0; j < M; j++) {
            int f; // Variable to store the fruit type at cell (i, j).
            cin >> f; // Read the fruit type from input.

            // Store the fruit type `f` in the flattened grid at the calculated index.
            grid[i * M + j] = f;

            // Calculate the two transformed coordinate values for the current cell (i, j).
            int p1 = i + j; // The sum transform
            int p2 = i - j; // The difference transform

            // Insert the calculated transforms into the corresponding multisets for fruit type `f`.
            // S1[f] keeps track of all (row+col) values for fruit f.
            S1[f].insert(p1);
            // S2[f] keeps track of all (row-col) values for fruit f.
            S2[f].insert(p2);
        }
    }

    // --- Query Processing ---
    int Q; // Number of queries to process.
    cin >> Q; // Read the number of queries.

    // Loop Q times to process each query.
    while (Q--) {
        int T; // Variable for the type of the current query (1 or 2).
        cin >> T; // Read the query type.

        // --- Query Type 1: Update Operation ---
        if (T == 1) {
            // This query updates the fruit type at a specific cell.
            int I, J, X; // Row (I), Column (J), New Fruit Type (X)
            cin >> I >> J >> X; // Read the update parameters.

            // Convert the 1-based input coordinates (I, J) to 0-based indices.
            --I;
            --J;

            // Calculate the index in the flattened grid corresponding to (I, J).
            int idx = I * M + J;
            // Get the fruit type currently at this location before the update.
            int old_fruit = grid[idx];

            // Optimization: If the new fruit type is the same as the old one,
            // no update is needed, so we can skip the rest and continue to the next query.
            if (old_fruit == X) continue;

            // If the fruit type is changing, we need to update our optimization structures (S1, S2).
            // Calculate the transforms for the cell being updated.
            int p1 = I + J;
            int p2 = I - J;

            // --- Remove old values from multisets ---
            // We need to remove the p1 and p2 values associated with the *old* fruit type.
            // IMPORTANT: Since `multiset` can have duplicates, we must remove only *one* instance
            // corresponding to this specific cell (I, J).
            // `S1[old_fruit].find(p1)` returns an iterator to the *first* occurrence of p1.
            auto it1 = S1[old_fruit].find(p1);
            // Check if the value was actually found before trying to erase it.
            // (This check prevents errors if the logic had a flaw, though it shouldn't happen here).
            if (it1 != S1[old_fruit].end()) {
                // `S1[old_fruit].erase(it1)` erases the element pointed to by the iterator `it1`.
                // This correctly removes only one instance even if duplicates exist.
                S1[old_fruit].erase(it1);
            }

            // Repeat the find-and-erase process for the p2 value in the S2 multiset.
            auto it2 = S2[old_fruit].find(p2);
            if (it2 != S2[old_fruit].end()) {
                S2[old_fruit].erase(it2);
            }

            // --- Insert new values into multisets ---
            // Now, insert the transforms p1 and p2 into the multisets associated with the *new* fruit type X.
            S1[X].insert(p1);
            S2[X].insert(p2);

            // --- Update the grid array ---
            // Finally, update the fruit type in the main grid array itself.
            grid[idx] = X;

        }
        // --- Query Type 2: Maximum Distance Query ---
        else {
            // This query asks for the maximum Manhattan distance between any cell
            // containing fruit U and any cell containing fruit V.
            int U, V; // The two fruit types to compare.
            cin >> U >> V; // Read the fruit types.

            // --- Sanity Check ---
            // Check if either fruit type U or V currently exists on the farm.
            // We can check emptiness of S1 (or S2, they should be consistent).
            // According to the problem statement, fruits U and V are guaranteed to exist,
            // so this check might be theoretically redundant but is good practice.
            if (S1[U].empty() || S1[V].empty()) {
                // If a fruit type doesn't exist, output -1 (or handle as appropriate).
                cout << -1 << "\n";
                continue; // Skip to the next query.
            }

            // --- Helper Lambda Functions ---
            // Define small, inline functions (lambdas) to easily get the minimum and maximum
            // values stored in the S1 and S2 multisets for a given fruit type `f`.
            // This makes the main calculation cleaner.

            // `max1(f)`: Returns the maximum (i+j) value for fruit `f`.
            // `S1[f].end()` points *past* the last element. `prev()` gets an iterator to the last element.
            // `*` dereferences the iterator to get the value. Assumes the set is not empty.
            auto max1 = [&](int f) { return *prev(S1[f].end()); };
            // `min1(f)`: Returns the minimum (i+j) value for fruit `f`.
            // `S1[f].begin()` points to the first (smallest) element.
            // `*` dereferences the iterator. Assumes the set is not empty.
            auto min1 = [&](int f) { return *S1[f].begin(); };
            // `max2(f)`: Returns the maximum (i-j) value for fruit `f`.
            auto max2 = [&](int f) { return *prev(S2[f].end()); };
            // `min2(f)`: Returns the minimum (i-j) value for fruit `f`.
            auto min2 = [&](int f) { return *S2[f].begin(); };

            // --- Calculate Maximum Distance ---
            int ans = 0; // Variable to store the result (maximum Manhattan distance).

            // Case 1: Find max distance between two points of the SAME fruit type (U == V).
            if (U == V) {
                // The maximum distance between two points of the same type U corresponds to the
                // largest "spread" within that type's transformed coordinates.
                // We calculate the difference between the max and min (i+j) values,
                // and the difference between the max and min (i-j) values.
                // The overall maximum distance is the larger of these two differences.
                ans = max(max1(U) - min1(U), // Max spread in (i+j) values for fruit U
                          max2(U) - min2(U)  // Max spread in (i-j) values for fruit U
                         );
            }
            // Case 2: Find max distance between points of DIFFERENT fruit types (U != V).
            else {
                // Based on the Manhattan distance property max(|Δ(i+j)|, |Δ(i-j)|),
                // the maximum distance between a point of type U and a point of type V
                // occurs when the difference between their (i+j) values OR the difference
                // between their (i-j) values is maximized.
                // We need to check the differences between the extreme values of the sets for U and V.
                // The required comparisons are:
                //  - Max (i+j) of U vs Min (i+j) of V
                //  - Max (i+j) of V vs Min (i+j) of U
                //  - Max (i-j) of U vs Min (i-j) of V
                //  - Max (i-j) of V vs Min (i-j) of U
                // The `max` function with an initializer list finds the largest among these four possibilities.
                ans = max({ // std::max can take an initializer_list
                    max1(U) - min1(V),
                    max1(V) - min1(U),
                    max2(U) - min2(V),
                    max2(V) - min2(U)
                });
            }

            // Output the calculated maximum distance for this query.
            cout << ans << "\n"; // "\n" adds a newline for correct output formatting.
        }
    }

    // Standard return value for successful execution of the main function.
    return 0;
}