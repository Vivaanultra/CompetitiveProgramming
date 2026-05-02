#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> x(n);
    vector<long long> prefix_sum(n + 1, 0);
    
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        prefix_sum[i + 1] = prefix_sum[i] + x[i];
    }

    // dp[i][j] = max score current player can get from range x[i...j]
    vector<vector<long long>> dp(n, vector<long long>(n));

    // Iterate through all possible lengths of the subarray
    for (int len = 1; len <= n; len++) {
        // Iterate through all start indices i
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            
            // Calculate sum of range [i, j] quickly
            long long current_range_sum = prefix_sum[j + 1] - prefix_sum[i];

            // Base case: range of length 1
            if (len == 1) {
                dp[i][j] = x[i];
            } else {
                // Opponent will play optimally on the remaining part
                // We take the Total Sum minus the Opponent's Best Outcome
                dp[i][j] = current_range_sum - min(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    // The answer for the full range [0, n-1]
    cout << dp[0][n - 1] << endl;

    return 0;
}