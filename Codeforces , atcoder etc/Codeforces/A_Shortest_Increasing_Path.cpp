#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y;
        cin >> x >> y;
        if (x == y) {
            cout << -1 << '\n';
        } else if (y > x) {
            // One step on x (a1 = x), second on y (a2 = y) with a2 > a1
            cout << 2 << '\n';
        } else { // x > y
            // Need y >= 2 and x - y >= 2 to be able to place a1 < y and a3 > y with a1 + a3 = x
            if (y >= 2 && (x - y) >= 2) cout << 3 << '\n';
            else cout << -1 << '\n';
        }
    }
    return 0;
}
