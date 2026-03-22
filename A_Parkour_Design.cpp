#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long x, y;
    cin >> x >> y;
 
    bool divisibleByThree = (x - 2 * y) % 3 == 0;

    if (divisibleByThree && (x >= 2 * y) && (x >= -4 * y)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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