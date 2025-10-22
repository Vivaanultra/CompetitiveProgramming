#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x;
        cin >> x;
        // If x is a power of two -> no solution
        if ((x & (x - 1)) == 0) {
            cout << -1 << '\n';
            continue;
        }
        long long ans = -1;
        for (int i = 0; i <= 30 && ans == -1; ++i) {
            for (int j = i; j <= 30 && ans == -1; ++j) {
                long long y = (1LL << i) | (1LL << j);
                if (y >= x) continue;
                long long a = x, b = y, c = x ^ y;
                if (a + b > c && a + c > b && b + c > a) {
                    ans = y;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
