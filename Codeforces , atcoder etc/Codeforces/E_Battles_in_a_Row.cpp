#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, h_max, m_max;
    cin >> n >> h_max >> m_max;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    vector<int> dp(h_max + 1, INF);
    dp[h_max] = 0;

    for (int i = 0; i < n; ++i) {
        vector<int> new_dp(h_max + 1, INF);
        bool can_defeat_current = false;

        for (int current_h = 0; current_h <= h_max; ++current_h) {
            if (dp[current_h] == INF) {
                continue;
            }

            if (current_h >= a[i]) {
                int next_h = current_h - a[i];
                new_dp[next_h] = min(new_dp[next_h], dp[current_h]);
                can_defeat_current = true;
            }

            int next_m = dp[current_h] + b[i];
            if (next_m <= m_max) {
                int next_h = current_h;
                new_dp[next_h] = min(new_dp[next_h], next_m);
                can_defeat_current = true;
            }
        }

        if (!can_defeat_current) {
            cout << i << endl;
            return 0;
        }
        
        dp = new_dp;
    }

    cout << n << endl;

    return 0;
}
