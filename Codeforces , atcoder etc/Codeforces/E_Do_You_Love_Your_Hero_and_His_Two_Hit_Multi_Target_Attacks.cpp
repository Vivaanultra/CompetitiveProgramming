#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        ll k;
        cin >> k;
        if (k == 0) {
            cout << 0 << "\n";
            continue;
        }

        // Build column sizes greedily: each column of size m gives C(m,2) pairs
        vector<int> cols;
        while (k > 0) {
            int l = 2, r = 500, best = 2;
            while (l <= r) {
                int mid = (l + r) >> 1;
                ll val = 1LL * mid * (mid - 1) / 2;
                if (val <= k) { best = mid; l = mid + 1; }
                else r = mid - 1;
            }
            cols.push_back(best);
            k -= 1LL * best * (best - 1) / 2;
        }

        int n = 0;
        for (int s : cols) n += s;
        // n should be <= 500 for given constraints; guard just in case
        if (n > 500) {
            // This fallback should practically never trigger for k <= 1e5.
            // As an emergency (not expected), output first 500 distinct points (no valid pairs).
            cout << 0 << "\n";
            continue;
        }

        cout << n << "\n";
        // Choose spacings so no accidental same-y or same-x across groups:
        const ll X_SP = 1000LL;
        const ll Y_SP = 1000000LL;
        ll idx = 0;
        for (int s : cols) {
            ll x = idx * X_SP;
            ll base_y = idx * Y_SP;
            for (int i = 0; i < s; ++i) {
                cout << x << " " << (base_y + i) << "\n";
            }
            ++idx;
        }
    }
    return 0;
}
