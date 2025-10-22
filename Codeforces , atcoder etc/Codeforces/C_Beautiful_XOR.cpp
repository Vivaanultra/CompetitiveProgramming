#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long a, b;
    cin >> a >> b;

    if (a == b) {
        cout << 0 << endl << endl;
        return;
    }

    if (__builtin_clzll(a) > __builtin_clzll(b)) {
        cout << -1 << endl;
        return;
    }

    long long intermediate = a | b;
    long long x1 = a ^ intermediate;
    long long x2 = intermediate ^ b;

    cout << 2 << endl;
    cout << x1 << " " << x2 << endl;
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