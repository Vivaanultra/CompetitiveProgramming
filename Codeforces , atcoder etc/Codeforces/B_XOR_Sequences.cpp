#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;

    // First, find the constant C = x XOR y.
    int c = x ^ y;

    // The length of the longest common subsegment is the value of the
    // least significant bit (LSB) of C.
    // The expression c & -c isolates this value.
    int ans = c & -c;

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