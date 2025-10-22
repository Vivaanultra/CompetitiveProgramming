#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long a, b;
    cin >> a >> b;

    if ((a % 2) != (b % 2)) {
        // Case 1: Different parities
        if (a % 2 != 0 && b % 2 == 0) { // a is odd, b is even
            if (b % 4 == 0) {
                cout << max(a * 2 + b / 2, a * (b / 2) + 2) << "\n";
            } else {
                cout << -1 << "\n";
            }
        } else { // a is even, b is odd
            cout << -1 << "\n";
        }
    } else {
        // Case 2: Same parities
        if (a % 2 != 0) { // Both are odd
            cout << max(a + b, a * b + 1) << "\n";
        } else { // Both are even
            cout << max(a + b, a * (b / 2) + 2) << "\n";
        }
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