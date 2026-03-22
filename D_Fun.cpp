#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    long long ans = 0;
    for (int a = 1; a < x; a++) {
        for (int b = 1; (long long)a * b < n; b++) {
            if (a + b >= x) break;
            int c1 = (n - (long long)a * b) / (a + b);
            int c2 = x - a - b;
            ans += min(c1, c2);
        }
    }
    cout << ans << "\n";
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