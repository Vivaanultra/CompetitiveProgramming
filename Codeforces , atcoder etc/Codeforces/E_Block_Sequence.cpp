#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> dp(n + 2, 0);

    for (int i = n - 1; i >= 0; --i) {
        // Choice 1: Skip a[i]
        dp[i] = dp[i + 1];

        // Choice 2: Use a[i] as a block header
        int jump_index = i + a[i] + 1;
        if (jump_index <= n) {
            dp[i] = max(dp[i], a[i] + 1 + dp[jump_index]);
        }
    }

    cout << n - dp[0] << "\n";
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