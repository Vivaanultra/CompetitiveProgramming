#include <bits/stdc++.h>

using namespace std;

void solve() {
    vector<long long> v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());

    long long a = v[0];
    long long b = v[1];
    long long c = v[2];

    if (a == b && b == c) {
        cout << "YES\n";
        return;
    }
    if (a == b && (c == 2 * a || c == 3 * a || c == 4 * a)) {
        cout << "YES\n";
        return;
    }
    if (b == 2 * a && (c == 2 * a || c == 3 * a)) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
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