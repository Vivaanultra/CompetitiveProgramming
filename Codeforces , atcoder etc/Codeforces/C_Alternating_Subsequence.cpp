#include <bits/stdc++.h> // Includes all standard C++ libraries
using namespace std;

// This function solves a single test case.
void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long total_sum = 0; // Use long long to prevent integer overflow

    // We iterate through the array using pointer 'i'.
    // The pointer 'j' will find the end of the current block of same-signed numbers.
    int i = 0;
    while (i < n) {
        // Determine the sign of the current block (1 for positive, -1 for negative)
        int current_sign = (a[i] > 0) ? 1 : -1;
        
        // This will be the largest number we find in the current block.
        long long block_max = a[i];
        
        // Move pointer 'j' forward as long as we are in the same block.
        int j = i + 1;
        while (j < n && ((a[j] > 0) ? 1 : -1) == current_sign) {
            // Update the maximum element found in this block so far.
            if (a[j] > block_max) {
                block_max = a[j];
            }
            j++;
        }
        
        // Add the largest element from the block to our total sum.
        total_sum += block_max;
        
        // Move the main pointer 'i' to the beginning of the next block.
        i = j;
    }

    cout << total_sum << endl;
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve();
    }

    return 0;
}