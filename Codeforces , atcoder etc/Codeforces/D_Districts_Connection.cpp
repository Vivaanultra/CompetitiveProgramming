#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    bool all_same = true;
    for (int i = 1; i < n; ++i) {
        if (a[i].first != a[0].first) {
            all_same = false;
            break;
        }
    }

    if (all_same) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    int hub1 = a[0].second;
    int hub2 = -1;
    for (int i = 1; i < n; ++i) {
        if (a[i].first != a[0].first) {
            hub2 = a[i].second;
            cout << hub1 << " " << hub2 << endl;
        }
    }

    for (int i = 1; i < n; ++i) {
        if (a[i].first == a[0].first) {
            cout << hub2 << " " << a[i].second << endl;
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