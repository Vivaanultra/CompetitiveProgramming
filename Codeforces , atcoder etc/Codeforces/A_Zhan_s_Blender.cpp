#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, x, y;
    cin >> n;
    cin >> x >> y;

    if (n == 0) {
        cout << 0 << "\n";
        return;
    }

    long long rate = min(x, y);
    long long time = (n + rate - 1) / rate;

    cout << time << "\n";
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