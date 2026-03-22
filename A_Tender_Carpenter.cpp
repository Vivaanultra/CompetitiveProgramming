#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For std::min and std::max
#include <climits>   // For INT_MAX

// Use standard namespace for concise code
using namespace std;

/**
 * @brief Solves a single test case for the carpenter problem.
 */
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // dp[i] = number of ways to partition the prefix a[0...i-1]
    // We cap the value at 2 (0, 1, or 2+)
    vector<int> dp(n + 1);
    
    // dp[0] = 1: One way to partition an empty prefix (do nothing)
    dp[0] = 1;

    // Iterate through all possible end-points 'i' of a partition
    // 'i' represents the length of the prefix
    for (int i = 1; i <= n; ++i) {
        dp[i] = 0;
        
        // Initialize min/max for the last subsegment
        int current_min = INT_MAX;
        int current_max = 0;

        // Iterate backward to find all possible start-points 'j'
        // for the last subsegment a[j-1 ... i-1]
        for (int j = i; j >= 1; --j) {
            // Update min/max for the subsegment ending at i-1 and starting at j-1
            int current_val = a[j - 1];
            current_min = min(current_min, current_val);
            current_max = max(current_max, current_val);

            // Check if the subsegment a[j-1 ... i-1] is stable
            // Use long long for the check to prevent potential overflow,
            // though with given constraints (10^5), it's just safe practice.
            if ((long long)2 * current_min > current_max) {
                
                // If stable, this is a valid partition.
                // Add the number of ways to partition everything *before* this subsegment.
                dp[i] += dp[j - 1];

                // We only care if there are 0, 1, or 2+ ways.
                // Cap at 2 to avoid overflow and unnecessary computation.
                if (dp[i] > 1) {
                    dp[i] = 2;
                }
            }
        }
    }

    // If dp[n] is 2 (or more), we have at least two ways.
    if (dp[n] >= 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    // Optimize C++ standard streams for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }
    return 0;
}