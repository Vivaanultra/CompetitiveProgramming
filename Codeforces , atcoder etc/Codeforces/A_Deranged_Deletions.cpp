#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        c[i] = a[i];
    }

    sort(c.begin(), c.end());

    vector<int> b;
    for (int i = 0; i < n; ++i) {
        if (a[i] != c[i]) {
            b.push_back(a[i]);
        }
    }

    if (b.empty()) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << b.size() << endl;
        for (int i = 0; i < b.size(); ++i) {
            cout << b[i] << (i == b.size() - 1 ? "" : " ");
        }
        cout << endl;
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