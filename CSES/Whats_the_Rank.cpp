#include <bits/stdc++.h> // Includes most standard libraries

using namespace std; // Use the standard namespace

// Maximum number of merchants (N). Fenwick tree will be indexed up to N.
// Using a slightly larger value for safety (e.g., N+5).
const int MAX_N_VAL = 45005; 

// Fenwick tree (Binary Indexed Tree). 
// It's 1-indexed in this implementation of update/query helpers,
// but takes 0-based discretized indices as input.
// Global arrays are zero-initialized by default.
int fenwick_tree[MAX_N_VAL]; 

// Stores the maximum index used in the Fenwick tree 
// (this will be the number of unique wealth values, M).
int fenwick_max_idx; 

// Function to update the Fenwick tree.
// Adds 'delta' (typically 1 for adding a merchant) to the element 
// corresponding to the 0-based 'discretized_idx'.
void update_fenwick_tree(int discretized_idx, int delta) {
    // Fenwick tree operations are often implemented with 1-based indexing.
    // So, convert the 0-based discretized_idx to a 1-based index.
    discretized_idx++; 
    
    // Traverse upwards in the conceptual tree structure of the Fenwick tree,
    // updating all relevant segment sums.
    for (; discretized_idx <= fenwick_max_idx; discretized_idx += discretized_idx & -discretized_idx) {
        fenwick_tree[discretized_idx] += delta;
    }
}

// Function to query the Fenwick tree.
// Returns the sum of elements from index 0 up to 'discretized_idx' (0-based, inclusive).
// In this problem, this sum represents the count of merchants (already processed and in the hall)
// whose discretized wealth is less than or equal to 'discretized_idx'.
int query_fenwick_tree(int discretized_idx) {
    // Convert the 0-based discretized_idx to a 1-based index for the query.
    discretized_idx++; 
    int sum = 0;
    // Traverse downwards (towards effective "parents" or smaller segments) 
    // in the Fenwick tree, accumulating the prefix sum.
    for (; discretized_idx > 0; discretized_idx -= discretized_idx & -discretized_idx) {
        sum += fenwick_tree[discretized_idx];
    }
    return sum;
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_merchants;
    cin >> n_merchants; // Read the total number of merchants

    // Stores the wealth of merchants in the original order they arrive.
    vector<int> arrival_wealths(n_merchants);
    // This vector will be used for coordinate compression:
    // It will first store all wealths, then be sorted to find unique values.
    vector<int> all_wealths_for_sorting(n_merchants);

    for (int i = 0; i < n_merchants; ++i) {
        cin >> arrival_wealths[i];
        all_wealths_for_sorting[i] = arrival_wealths[i]; // Copy for sorting
    }

    // --- Step 1: Coordinate Compression ---
    // Sort all collected wealth values to prepare for finding unique values and their ranks.
    sort(all_wealths_for_sorting.begin(), all_wealths_for_sorting.end());
    
    // Remove duplicate wealth values. After this, 'all_wealths_for_sorting'
    // contains only unique wealths, sorted in ascending order.
    all_wealths_for_sorting.erase(
        unique(all_wealths_for_sorting.begin(), all_wealths_for_sorting.end()),
        all_wealths_for_sorting.end()
    );

    // 'fenwick_max_idx' is the number of unique wealth values (M).
    // This determines the effective range of indices for our Fenwick tree.
    fenwick_max_idx = all_wealths_for_sorting.size(); 
    // The 'fenwick_tree' array itself is already declared globally and is zero-initialized.

    // Keeps track of how many merchants have been processed and their wealth
    // recorded in the Fenwick tree.
    int merchants_processed_so_far = 0;

    // --- Step 2 & 3: Process merchants, calculate rank, and update Fenwick tree ---
    // Process each merchant in their order of arrival.
    for (int i = 0; i < n_merchants; ++i) {
        int current_merchant_wealth = arrival_wealths[i];

        // Find the 0-based discretized index for the current merchant's wealth.
        // This maps the potentially large actual wealth value to a smaller integer (from 0 to M-1).
        // lower_bound finds the first element in 'all_wealths_for_sorting'
        // that is not less than 'current_merchant_wealth'.
        // Subtracting '.begin()' gives its 0-based index in this sorted unique list.
        int discretized_wealth_idx = lower_bound(all_wealths_for_sorting.begin(), 
                                                 all_wealths_for_sorting.end(), 
                                                 current_merchant_wealth) 
                                     - all_wealths_for_sorting.begin();

        // --- Calculate Rank ---
        // Query the Fenwick tree: How many merchants *already in the hall*
        // have a wealth less than or equal to the current merchant's wealth?
        // (This uses their discretized wealth values for comparison).
        int count_poorer_or_equal_in_hall = query_fenwick_tree(discretized_wealth_idx);
        
        // The number of merchants *already in the hall* who are richer than the current merchant:
        // (Total merchants processed so far) - (Merchants poorer than or equal to current).
        // Since all wealths are distinct as per problem constraints, and the current merchant
        // is not yet in the Fenwick tree, 'count_poorer_or_equal_in_hall' effectively counts
        // those strictly poorer among the ones already present.
        int count_richer_in_hall = merchants_processed_so_far - count_poorer_or_equal_in_hall;
        
        // The rank is defined as 1 + (number of richer merchants already in the hall).
        int rank = count_richer_in_hall + 1;
        cout << rank << "\n"; // Output the calculated rank

        // --- Update State ---
        // Add the current merchant's (discretized) wealth to the Fenwick tree.
        // This signifies that a merchant with this wealth is now in the hall.
        update_fenwick_tree(discretized_wealth_idx, 1);
        
        // Increment the count of total merchants processed and added to the hall.
        merchants_processed_so_far++;
    }

    return 0;
}