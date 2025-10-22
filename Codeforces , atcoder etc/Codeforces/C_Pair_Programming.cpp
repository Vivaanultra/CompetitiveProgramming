#include <bits/stdc++.h>

using namespace std;

void solve() {
    int k, n, m;
    cin >> k >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    int ptr_a = 0;
    int ptr_b = 0;
    vector<int> result;

    while (ptr_a < n || ptr_b < m) {
        if (ptr_a < n && a[ptr_a] == 0) {
            result.push_back(0);
            k++;
            ptr_a++;
        } else if (ptr_b < m && b[ptr_b] == 0) {
            result.push_back(0);
            k++;
            ptr_b++;
        } else if (ptr_a < n && a[ptr_a] <= k) {
            result.push_back(a[ptr_a]);
            ptr_a++;
        } else if (ptr_b < m && b[ptr_b] <= k) {
            result.push_back(b[ptr_b]);
            ptr_b++;
        } else {
            cout << -1 << endl;
            return;
        }
    }

    for (int i = 0; i < n + m; ++i) {
        cout << result[i] << (i == n + m - 1 ? "" : " ");
    }
    cout << endl;
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