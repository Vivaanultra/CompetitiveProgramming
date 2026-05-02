#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;

    if (k > n) {
        cout << -1 << "\n";
        return;
    }

    for (int d = 0; d <= 32; ++d) {
        long long parts = 1LL << d;
        long long val1 = n / parts;
        long long val2 = (n + parts - 1) / parts;

        if (val1 == k || val2 == k) {
            cout << d << "\n";
            return;
        }

        if (val2 < k) {
            break;
        }
    }

    cout << -1 << "\n";
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