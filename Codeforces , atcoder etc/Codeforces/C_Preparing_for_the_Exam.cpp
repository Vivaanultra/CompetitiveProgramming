#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m);
    vector<int> q(k);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < k; ++i) {
        cin >> q[i];
    }

    int unknown_count = n - k;

    if (unknown_count >= 2) {
        for (int i = 0; i < m; ++i) {
            cout << '0';
        }
        cout << "\n";
        return;
    }

    if (unknown_count == 0) {
        for (int i = 0; i < m; ++i) {
            cout << '1';
        }
        cout << "\n";
        return;
    }

    vector<bool> known(n + 1, false);
    for (int val : q) {
        known[val] = true;
    }

    int the_one_unknown = -1;
    for (int i = 1; i <= n; ++i) {
        if (!known[i]) {
            the_one_unknown = i;
            break;
        }
    }

    string result = "";
    for (int val : a) {
        if (val == the_one_unknown) {
            result += '1';
        } else {
            result += '0';
        }
    }
    cout << result << "\n";
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