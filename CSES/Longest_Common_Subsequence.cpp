#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];

    // dp[i][j] stores the length of LCS of a[0...i-1] and b[0...j-1]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // 1. Fill the DP Table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[n][m] << endl;

    // 2. Backtrack to find the actual elements
    vector<int> lcs;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        // If current elements match, they are part of the LCS
        if (a[i-1] == b[j-1]) {
            lcs.push_back(a[i-1]);
            i--;
            j--;
        }
        // If not, move in the direction of the larger value
        else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    // The backtracking finds elements in reverse order
    reverse(lcs.begin(), lcs.end());

    for (int k = 0; k < lcs.size(); k++) {
        cout << lcs[k] << (k == lcs.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}