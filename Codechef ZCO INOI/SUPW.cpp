#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> minutes(n);
    for (int i = 0; i < n; ++i) {
        cin >> minutes[i];
    }

    if (n <= 3) {
        int min_val = minutes[0];
        for (int i = 1; i < n; ++i) {
            min_val = min(min_val, minutes[i]);
        }
        cout << min_val << "\n";
        return 0;
    }

    vector<long long> dp(n, 0);

    dp[0] = minutes[0];
    dp[1] = minutes[1];
    dp[2] = minutes[2];

    for (int i = 3; i < n; ++i) {
        dp[i] = minutes[i] + min({dp[i - 1], dp[i - 2], dp[i - 3]});
    }

    cout << min({dp[n - 1], dp[n - 2], dp[n - 3]}) << "\n";

    return 0;
}