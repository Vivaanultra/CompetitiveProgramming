#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, x;
    cin >> n >> x;

    if (x == 0) {
        if (n == 1) {
            cout << -1 << endl;
        } else if (n % 2 == 0) {
            cout << n << endl;
        } else {
            cout << n + 3 << endl;
        }
    } else if (x == 1) {
        if (n % 2 != 0) {
            cout << n << endl;
        } else {
            cout << n + 3 << endl;
        }
    } else {
        int c = __builtin_popcountll(x);
        if (n <= c) {
            cout << x << endl;
        } else {
            long long diff = n - c;
            if (diff % 2 == 0) {
                cout << x + diff << endl;
            } else {
                cout << x + diff + 1 << endl;
            }
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