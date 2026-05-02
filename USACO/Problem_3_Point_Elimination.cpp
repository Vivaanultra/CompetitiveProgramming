#include <bits/stdc++.h>
using namespace std;

pair<int, int> solve_1D(const map<int, int>& freq) {
    if (freq.empty()) return {0, 0};
    vector<pair<int, int>> arr(freq.begin(), freq.end());
    int min_total = 0, max_total = 0;

    for (size_t i = 0; i < arr.size(); ) {
        size_t j = i;
        while (j + 1 < arr.size() && arr[j + 1].first == arr[j].first + 1) {
            j++;
        }
        int k = j - i + 1;
        vector<int> C(k);
        for (int idx = 0; idx < k; ++idx) {
            C[idx] = arr[i + idx].second;
        }

        int req = 0;
        int min_E = 0;
        vector<int> reqs(k);
        for (int idx = 0; idx < k; ++idx) {
            req = (C[idx] - req) % 2;
            if (req < 0) req += 2;
            reqs[idx] = req;
            min_E += req;
        }
        if (req != 0) return {-1, -1};

        vector<int> dp(C[0] + 1, -1);
        for (int e = reqs[0]; e <= C[0]; e += 2) {
            dp[e] = e;
        }
        int prev_req = reqs[0];

        for (int idx = 1; idx < k; ++idx) {
            int curr_req = reqs[idx];
            vector<int> new_dp(C[idx] + 1, -1);
            vector<int> pref(C[idx - 1] + 1, -1);
            int max_val = -1;
            for (int x = 0; x <= C[idx - 1]; ++x) {
                if (x % 2 == prev_req && dp[x] != -1) {
                    max_val = max(max_val, dp[x]);
                }
                pref[x] = max_val;
            }

            for (int e = curr_req; e <= C[idx]; e += 2) {
                int limit = C[idx] - e;
                limit = min(limit, C[idx - 1]);
                if (limit >= 0 && pref[limit] != -1) {
                    new_dp[e] = e + pref[limit];
                }
            }
            dp = move(new_dp);
            prev_req = curr_req;
        }
        min_total += min_E;
        max_total += dp[0];
        i = j + 1;
    }
    return {min_total, max_total};
}

void solve() {
    int n;
    cin >> n;
    map<int, int> fx, fy;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        fx[x]++;
        fy[y]++;
    }
    auto [minX, maxX] = solve_1D(fx);
    auto [minY, maxY] = solve_1D(fy);

    if (minX == -1 || minY == -1) {
        cout << "NO\n";
        return;
    }

    if ((minX + minY) % 2 != (n / 2) % 2) {
        cout << "NO\n";
        return;
    }
    
    if (minX + minY <= n / 2 && maxX + maxY >= n / 2) {
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