#include <iostream>
#include <string>
#include <vector>
#include <cstring> // For memset

// Use competitive programming standard headers and practices
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

string N;
int len;
long long memo[100005][11][11][2];

long long dp(int pos, int sum_mod, int num_mod, bool tight) {
    if (pos == len) {
        return (sum_mod == 0 && num_mod == 0);
    }

    if (memo[pos][sum_mod][num_mod][tight] != -1) {
        return memo[pos][sum_mod][num_mod][tight];
    }

    long long ans = 0;
    int limit = tight ? (N[pos] - '0') : 9;

    for (int d = 0; d <= limit; ++d) {
        bool new_tight = tight && (d == limit);
        int new_sum_mod = (sum_mod + d) % 11;
        int new_num_mod = (num_mod * 10 + d) % 11;
        ans = (ans + dp(pos + 1, new_sum_mod, new_num_mod, new_tight)) % MOD;
    }

    return memo[pos][sum_mod][num_mod][tight] = ans;
}

void solve() {
    cin >> N;
    len = N.length();

    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < 11; ++j) {
            for (int k = 0; k < 11; ++k) {
                memo[i][j][k][0] = -1;
                memo[i][j][k][1] = -1;
            }
        }
    }

    long long count_up_to_N = dp(0, 0, 0, true);
    long long ans = (count_up_to_N - 1 + MOD) % MOD;
    
    cout << ans << endl;
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