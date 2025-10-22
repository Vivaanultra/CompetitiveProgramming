#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    vector<int> total_dp(k, -1);
    total_dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        vector<vector<int>> row_dp(m / 2 + 1, vector<int>(k, -1));
        row_dp[0][0] = 0;

        for (int val : a[i]) {
            for (int count = m / 2; count >= 1; --count) {
                for (int rem = 0; rem < k; ++rem) {
                    int prev_rem = (rem - (val % k) + k) % k;
                    if (row_dp[count - 1][prev_rem] != -1) {
                        row_dp[count][rem] = max(row_dp[count][rem], row_dp[count - 1][prev_rem] + val);
                    }
                }
            }
        }

        vector<int> current_row_best(k, -1);
        for (int rem = 0; rem < k; ++rem) {
            for (int count = 0; count <= m / 2; ++count) {
                current_row_best[rem] = max(current_row_best[rem], row_dp[count][rem]);
            }
        }

        vector<int> new_total_dp(k, -1);
        for (int rem1 = 0; rem1 < k; ++rem1) {
            if (total_dp[rem1] == -1) continue;
            for (int rem2 = 0; rem2 < k; ++rem2) {
                if (current_row_best[rem2] == -1) continue;
                
                int new_rem = (rem1 + rem2) % k;
                new_total_dp[new_rem] = max(new_total_dp[new_rem], total_dp[rem1] + current_row_best[rem2]);
            }
        }
        total_dp = new_total_dp;
    }

    cout << max(0, total_dp[0]) << endl;

    return 0;
}