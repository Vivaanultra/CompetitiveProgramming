#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    if (!(cin >> s1 >> s2)) return 0;

    int n = s1.size();
    int m = s2.size();

    // dp[i][j] stores the edit distance between s1[0...i-1] and s2[0...j-1]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    // Base Case: First Row (Converting empty string to s2 prefix)
    for (int j = 0; j <= m; j++) {
        dp[0][j] = j;
    }

    // Base Case: First Column (Converting s1 prefix to empty string)
    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }

    // Fill the grid
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // If characters match (0 cost for this step)
            // Note: strings are 0-indexed, so we look at s1[i-1]
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } 
            // If mismatch, take min of 3 neighbors + 1
            else {
                dp[i][j] = 1 + min({
                    dp[i][j-1],    // Add
                    dp[i-1][j],    // Remove
                    dp[i-1][j-1]   // Replace
                });
            }
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}