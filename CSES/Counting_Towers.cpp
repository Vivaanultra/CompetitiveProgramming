#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1000005;

// dp[i][0] -> Ends with Separate | |
// dp[i][1] -> Ends with United   [  ]
long long dp[MAXN][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Base Case: Height 1
    dp[1][0] = 1; // The tower is just two 1x1 blocks
    dp[1][1] = 1; // The tower is just one 2x1 block

    // Precompute for all heights up to 1 million
    for (int i = 2; i < MAXN; i++) {
        // Calculate ways to make a Separate row at height i
        // From Separate (x4) + From United (x1)
        dp[i][0] = (4 * dp[i-1][0] + dp[i-1][1]) % MOD;

        // Calculate ways to make a United row at height i
        // From Separate (x1) + From United (x2)
        dp[i][1] = (dp[i-1][0] + 2 * dp[i-1][1]) % MOD;
    }

    int t;
    if (cin >> t) {
        while (t--) {
            int n;
            cin >> n;
            // Total ways is sum of both ending types
            cout << (dp[n][0] + dp[n][1]) % MOD << "\n";
        }
    }
    return 0;
}