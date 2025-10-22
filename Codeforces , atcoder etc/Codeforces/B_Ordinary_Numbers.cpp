#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    for (long long p = 1; p <= n; p = p * 10 + 1) {
        for (int d = 1; d <= 9; ++d) {
            if (p * d <= n) {
                ans++;
            }
        }
    }
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