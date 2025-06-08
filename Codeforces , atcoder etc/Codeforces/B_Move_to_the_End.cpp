#include <iostream> // For input/output operations (cin, cout)
#include <vector>   // For using dynamic arrays (std::vector)
#include <algorithm> // For std::max

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n; // Read the size of the array
    std::vector<long long> a(n); // Declare a vector to store array elements (using long long for large sums)
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i]; // Read each element of the array
    }

    // Constraints state 1 <= n, so n will not be 0.

    // Precompute prefix maximums
    // pref_max[i] will store the maximum value in the subarray a[0...i]
    std::vector<long long> pref_max(n);
    if (n > 0) { // Check for non-empty array (guaranteed by constraints but good practice)
        pref_max[0] = a[0];
        for (int i = 1; i < n; ++i) {
            pref_max[i] = std::max(pref_max[i - 1], a[i]);
        }
    }

    // Precompute suffix sums
    // suff[i] will store the sum of elements a[i...n-1]
    // suff[n] is conceptually 0 (sum of an empty range)
    std::vector<long long> suff(n + 1, 0LL); // Size n+1, initialized to 0. suff[n] = 0.
    for (int i = n - 1; i >= 0; --i) {
        suff[i] = suff[i + 1] + a[i];
    }

    std::vector<long long> results; // To store the answer for each k
    results.reserve(n); // Reserve space to avoid reallocations

    // Iterate for each k from 1 to n
    for (int k = 1; k <= n; ++k) {
        long long max_sum_for_k = 0; 

        // Candidate 1: Based on moving max(a[0]...a[n-k]) to the end.
        // The element moved is pref_max[n-k].
        // The other k-1 elements are the original last k-1 elements, sum = suff[n-(k-1)].
        long long val_moved_cand1 = pref_max[n - k]; // Max element from a[0]...a[n-k]
        long long sum_others_cand1 = 0;
        if (k - 1 > 0) {
            // Sum of original last k-1 elements: a[n-(k-1)]...a[n-1]
            sum_others_cand1 = suff[n - (k - 1)];
        }
        long long candidate1_sum = val_moved_cand1 + sum_others_cand1;
        max_sum_for_k = candidate1_sum;

        // Candidate 2: Based on moving an element from the original last k elements.
        // The sum becomes the sum of the original last k elements: a[n-k]...a[n-1].
        // This sum is suff[n-k].
        long long candidate2_sum = suff[n - k];
        max_sum_for_k = std::max(max_sum_for_k, candidate2_sum);
        
        results.push_back(max_sum_for_k); // Store the best sum found for this k
    }

    // Print the results for the current test case
    for (int i = 0; i < n; ++i) {
        std::cout << results[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

int main() {
    // Fast I/O setup
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }
    return 0;
}