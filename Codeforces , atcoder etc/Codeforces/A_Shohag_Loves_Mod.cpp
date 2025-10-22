#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        // The sequence of odd numbers (2*i - 1) satisfies all conditions.
        // It's increasing, and (2*i-1) mod i = i-1, making all remainders unique.
        cout << 2 * i - 1 << (i == n ? "" : " ");
    }
    cout << endl;
}

int main() {
    // It is currently Thursday, 11:18 PM in Mathura, India.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}