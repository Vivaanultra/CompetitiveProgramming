#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long s, k, m;
    cin >> s >> k >> m;

    if (k >= s) {
        long long rem = m % k;
        if (rem >= s) {
            cout << 0 << "\n";
        } else {
            cout << s - rem << "\n";
        }
    } else {
        long long cycle = 2 * k;
        long long rem = m % cycle;
        if (rem < k) {
            cout << s - rem << "\n";
        } else {
            cout << cycle - rem << "\n";
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