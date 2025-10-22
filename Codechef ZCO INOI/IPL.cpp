#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> F(n);
    for (int i = 0; i < n; ++i) {
        cin >> F[i];
    }

    if (n == 0) {
        cout << 0 << "\n";
        return;
    }

    vector<long long> dp(n, 0);

    dp[0] = F[0];

    if (n >= 2) {
        dp[1] = F[0] + F[1];
    }

    if (n >= 3) {
        dp[2] = max({F[0] + F[1], F[0] + F[2], F[1] + F[2]});
    }

    for (int i = 3; i < n; ++i) {
        long long choice1 = dp[i - 1];
        long long choice2 = F[i] + dp[i - 2];
        long long choice3 = F[i] + F[i - 1] + dp[i - 3];
        dp[i] = max({choice1, choice2, choice3});
    }

    cout << dp[n - 1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();

    return 0;
}