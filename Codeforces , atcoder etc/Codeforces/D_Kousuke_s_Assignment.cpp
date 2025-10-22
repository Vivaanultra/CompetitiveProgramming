#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> ps(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        ps[i + 1] = ps[i] + a[i];
    }

    vector<int> dp(n + 1, 0);
    map<long long, int> max_dp_for_sum;
    max_dp_for_sum[0] = 0;

    for (int i = 1; i <= n; ++i) {
        // Case 1: Don't end a segment here
        dp[i] = dp[i - 1];

        // Case 2: Check if we CAN end a segment here
        if (max_dp_for_sum.count(ps[i])) {
            int prev_dp = max_dp_for_sum[ps[i]];
            dp[i] = max(dp[i], prev_dp + 1);
        }

        // Update the map with the best result ending at or before `i`
        // for the prefix sum ps[i].
        max_dp_for_sum[ps[i]] = max(max_dp_for_sum[ps[i]], dp[i]);
    }

    cout << dp[n] << "\n";
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