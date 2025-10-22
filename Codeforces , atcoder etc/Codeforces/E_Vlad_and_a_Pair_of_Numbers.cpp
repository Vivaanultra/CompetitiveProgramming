#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x;
    cin >> x;

    // Condition 1: x must be even.
    // Condition 2: The set bits of x and x/2 must not overlap.
    // x & (x / 2) is a concise way to check if x has adjacent set bits.
    // If it does, the condition fails.
    if (x % 2 != 0 || (x & (x / 2)) != 0) {
        cout << -1 << endl;
        return;
    }

    // LSOne(x) is typically x & -x
    int lsone = x & -x;

    int a = (x / 2) + lsone;
    int b = (x / 2) + (x ^ lsone);

    // An alternative simpler construction is:
    // int a = x + (x / 2);
    // int b = x / 2;

    cout << a << " " << b << endl;
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
