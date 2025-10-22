#include <bits/stdc++.h>

using namespace std;

void solve() {
    string a, b, c;
    cin >> a >> b >> c;

    int n = a.length();
    int m = b.length();

    // dp[i][j] stores the max matches using a's prefix of length i and b's of length j.
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Base cases for the first row and column
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = dp[i - 1][0];
        if (a[i - 1] == c[i - 1]) {
            dp[i][0]++;
        }
    }

    for (int j = 1; j <= m; ++j) {
        dp[0][j] = dp[0][j - 1];
        if (b[j - 1] == c[j - 1]) {
            dp[0][j]++;
        }
    }

    // Fill the rest of the DP table using the recurrence relation
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            // Option 1: The last character came from string a
            int matches_from_a = dp[i - 1][j] + (a[i - 1] == c[i + j - 1]);

            // Option 2: The last character came from string b
            int matches_from_b = dp[i][j - 1] + (b[j - 1] == c[i + j - 1]);

            dp[i][j] = max(matches_from_a, matches_from_b);
        }
    }

    int max_matches = dp[n][m];
    int total_length = n + m;

    cout << total_length - max_matches << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}