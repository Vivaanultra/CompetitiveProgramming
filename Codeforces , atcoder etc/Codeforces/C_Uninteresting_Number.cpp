#include<bits/stdc++.h>
using namespace std;

void solve() {
    string n_str;
    cin >> n_str;

    vector<bool> dp(9, false);
    dp[0] = true;

    for (char digit_char : n_str) {
        int digit = digit_char - '0';
        vector<bool> next_dp(9, false);

        for (int j = 0; j < 9; ++j) {
            if (dp[j]) {
                // Option 1: Keep the original digit
                next_dp[(j + digit) % 9] = true;

                // Option 2: Transform the digit if possible
                if (digit == 2) {
                    next_dp[(j + 4) % 9] = true;
                } else if (digit == 3) {
                    next_dp[(j + 9) % 9] = true; // (j + 0) % 9
                }
            }
        }
        dp = next_dp;
    }

    if (dp[0]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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