#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, k, p;
    cin >> n >> k >> p;

    // The minimum number of operations is |k| divided by p, rounded up.
    // In integer arithmetic, ceil(A/B) for positive A, B is (A + B - 1) / B.
    long long min_ops = (abs(k) + p - 1) / p;

    // Check if the number of required operations exceeds the array size.
    if (min_ops > n) {
        cout << -1 << "\n";
    } else {
        cout << min_ops << "\n";
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