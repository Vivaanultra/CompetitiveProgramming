#include <iostream>
#include <vector>
#include <numeric>

// Including the entire standard library for convenience in competitive programming.
#include <bits/stdc++.h>

// Using the standard namespace to avoid typing std:: repeatedly.
using namespace std;

// This function solves a single test case of the problem.
void solve() {
    int n, k;
    cin >> n >> k;
    // Using long long for array elements to prevent overflow when calculating 2 * a[i+1]
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // The core condition is 2^j * a_{i+j} < 2^{j+1} * a_{i+j+1} for j=0..k-1.
    // This simplifies by dividing both sides by 2^j to: a_{i+j} < 2 * a_{i+j+1}.
    // This simple inequality must hold for k consecutive pairs.

    // Step 1: Pre-calculate the result of each adjacent comparison.
    // Create a binary array `checks` where checks[i] is 1 if a[i] < 2*a[i+1], else 0.
    vector<int> checks(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] < 2 * a[i + 1]) {
            checks[i] = 1;
        } else {
            checks[i] = 0;
        }
    }

    // Step 2: Use prefix sums to quickly find the number of satisfied
    // conditions in any given window of k comparisons.
    vector<int> prefix_sum(n - 1, 0);
    if (n > 1) {
        prefix_sum[0] = checks[0];
        for (int i = 1; i < n - 1; ++i) {
            prefix_sum[i] = prefix_sum[i - 1] + checks[i];
        }
    }

    // Step 3: Iterate through all possible starting positions and check their corresponding window.
    // A starting index `i` (0-based) for subarray a[i...i+k] is valid if the k comparisons
    // starting from `a[i]` vs `a[i+1]` are all true.
    // This corresponds to the window checks[i...i+k-1] having a sum of k.
    int ans_count = 0;
    // The loop for 0-based starting positions `i` of the subarray a[i...i+k]
    // goes from i=0 to i=n-k-1.
    for (int i = 0; i <= n - k - 1; ++i) {
        // The window of `checks` is from index i to i+k-1.
        int window_end = i + k - 1;
        
        int window_sum;
        if (i == 0) {
            // For the first window, the sum is just the prefix_sum at the end.
            window_sum = prefix_sum[window_end];
        } else {
            // For other windows, it's the difference of two prefix sums.
            window_sum = prefix_sum[window_end] - prefix_sum[i - 1];
        }

        if (window_sum == k) {
            ans_count++;
        }
    }

    cout << ans_count << "\n";
}

int main() {
    // Standard competitive programming setup for fast I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases.
    while (t--) {
        solve();
    }

    return 0;
}