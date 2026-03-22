#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    long long total_sum = (long long)n * (n + 1) / 2;

    // If sum is odd, impossible to split
    if (total_sum % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }

    int target = total_sum / 2;
    int mod = 1e9 + 7;

    // dp[i] = number of ways to make sum 'i'
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    // Iterate through numbers 1 to n
    for (int num = 1; num <= n; num++) {
        // Iterate backwards to use each number exactly once
        for (int j = target; j >= num; j--) {
            dp[j] = (dp[j] + dp[j - num]) % mod;
        }
    }

    // Multiply by modular inverse of 2 (which is (MOD+1)/2)
    // Because we counted {Set A} and {Set B} as distinct, but {A, B} is one partition.
    long long ans = dp[target];
    ans = (ans * 500000004) % mod;

    cout << ans << endl;

    return 0;
}