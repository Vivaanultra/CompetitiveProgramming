#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];

    sort(a.rbegin(), a.rend());

    long long ans = 0;
    long long needed = 0;

    for (int i = 0; i < n; i++) {
        needed += b[i];
        if (needed > n) break;
        ans = max(ans, (long long)(i + 1) * a[needed - 1]);
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