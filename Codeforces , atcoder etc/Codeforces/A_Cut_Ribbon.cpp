#include <iostream>
#include <vector>
#include <algorithm> // Required for std::max

// It's a common competitive programming practice to include bits/stdc++.h
// but for clarity, specific headers are used here.
// For competitive programming, you might use:
// #include <bits/stdc++.h>
using namespace std;

int main() {
    // Fast I/O - common in competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    // dp[i] will store the maximum number of pieces for a ribbon of length i.
    // Initialize dp array.
    // dp[0] = 0 because a ribbon of length 0 results in 0 pieces.
    // Other dp[i] are initialized to -1, indicating that a ribbon of length i
    // cannot be formed yet or is impossible with the given piece lengths.
    vector<int> dp(n + 1, -1);
    dp[0] = 0;

    // Iterate through all possible ribbon lengths from 1 to n
    for (int i = 1; i <= n; ++i) {
        // Try to form length 'i' by adding a piece of length 'a', 'b', or 'c'
        // to a previously optimally cut ribbon.

        // Option 1: Last piece has length 'a'
        if (i >= a && dp[i - a] != -1) {
            // If length 'i-a' is possible to form (dp[i-a] is not -1),
            // then we can potentially form length 'i' with dp[i-a] + 1 pieces.
            // We take the maximum with the current dp[i] (which might be -1 or from another option).
            dp[i] = max(dp[i], dp[i - a] + 1);
        }

        // Option 2: Last piece has length 'b'
        if (i >= b && dp[i - b] != -1) {
            // If length 'i-b' is possible
            dp[i] = max(dp[i], dp[i - b] + 1);
        }

        // Option 3: Last piece has length 'c'
        if (i >= c && dp[i - c] != -1) {
            // If length 'i-c' is possible
            dp[i] = max(dp[i], dp[i - c] + 1);
        }
    }

    // The answer is the maximum number of pieces for the original ribbon length n.
    // The problem guarantees that at least one correct ribbon cutting exists,
    // so dp[n] will be non-negative.
    cout << dp[n] << endl;

    return 0;
}