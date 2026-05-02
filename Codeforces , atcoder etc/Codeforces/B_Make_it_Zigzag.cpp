#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long ans = 0;
    long long cur = max(a[0], a[1]);
    if (a[0] >= cur) {
        ans += a[0] - cur + 1;
    }
    for (int i = 2; i < n - 1; i += 2) {
        long long pot = max({a[i], a[i + 1], cur});
        long long limit = min(cur, pot) - 1;
        if (a[i] > limit) {
            ans += a[i] - limit;
        }
        cur = pot;
    }
    if (n % 2 != 0) {
        if (a[n - 1] >= cur) {
            ans += a[n - 1] - cur + 1;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}