#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int last_inversion = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i+1]) {
            last_inversion = i;
        }
    }

    if (last_inversion == -1) {
        cout << 0 << "\n";
    } else {
        int max_val = 0;
        for (int i = 0; i <= last_inversion; ++i) {
            max_val = max(max_val, a[i]);
        }
        cout << max_val << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}