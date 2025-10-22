#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        vector<int> b(k);
        for (int i = 0; i < k; ++i) cin >> b[i];

        sort(a.begin(), a.end());       // ascending
        sort(b.begin(), b.end());       // ascending

        long long ans = 0;
        for (long long v : a) ans += v;

        int id = n; // number of items not yet "consumed" from the left (0-based: next free index is id-1)
        for (int i = 0; i < k; ++i) {
            id -= b[i];
            if (id >= 0) {
                // a[id] is the cheapest element in this voucher-group (0-based)
                ans -= a[id];
            } else {
                // no more full groups can be formed; further vouchers cannot free anything
                break;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
