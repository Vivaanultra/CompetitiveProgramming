#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        long long ans = 0;
        // If n is even -> sum a[1], a[3], ...
        // If n is odd  -> sum a[0], a[2], ...
        int start = (n % 2 == 0) ? 1 : 0;
        for (int i = start; i < n; i += 2) ans += a[i];
        cout << ans << '\n';
    }
    return 0;
}
