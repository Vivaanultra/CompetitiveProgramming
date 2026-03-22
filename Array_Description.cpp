#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    // dp[i][v] = number of valid prefixes of length i+1 ending with value v
    // We use a 2D vector. Dimensions: n x (m+2) to handle boundaries easily (0 and m+1)
    vector<vector<int>> dp(n, vector<int>(m + 2, 0));
    int mod = 1e9 + 7;

    // Base Case: First element (Index 0)
    if (x[0] == 0) {
        for (int v = 1; v <= m; v++) {
            dp[0][v] = 1;
        }
    } else {
        dp[0][x[0]] = 1;
    }

    // Fill the rest
    for (int i = 1; i < n; i++) {
        // If current position is unknown (0), we try all values 1..m
        if (x[i] == 0) {
            for (int v = 1; v <= m; v++) {
                // Sum of valid previous states: v-1, v, v+1
                long long ways = dp[i-1][v-1];
                ways += dp[i-1][v];
                ways += dp[i-1][v+1];
                
                dp[i][v] = ways % mod;
            }
        } 
        // If current position is fixed, we only calculate for that specific value
        else {
            int v = x[i];
            long long ways = dp[i-1][v-1];
            ways += dp[i-1][v];
            ways += dp[i-1][v+1];
            
            dp[i][v] = ways % mod;
        }
    }

    // The answer is the sum of all valid endings at the last position
    int ans = 0;
    for (int v = 1; v <= m; v++) {
        ans = (ans + dp[n-1][v]) % mod;
    }

    cout << ans << endl;

    return 0;
}