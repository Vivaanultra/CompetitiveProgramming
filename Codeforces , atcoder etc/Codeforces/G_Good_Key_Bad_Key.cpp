#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    const int HALVING_CAP = 35;
    vector<vector<long long>> dp(n + 1, vector<long long>(HALVING_CAP + 1, -3e18));

    for (int h = 0; h <= HALVING_CAP; ++h) {
        dp[n][h] = 0;
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int h = 0; h <= HALVING_CAP; ++h) {
            long long profit_good = (a[i] >> h) - k + dp[i + 1][h];

            long long profit_bad;
            int next_h = h + 1;
            if (next_h > HALVING_CAP) {
                profit_bad = 0;
            } else {
                profit_bad = (a[i] >> next_h) + dp[i + 1][next_h];
            }
            
            dp[i][h] = max(profit_good, profit_bad);
        }
    }

    cout << dp[0][0] << "\n";
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