#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    long long max_diff = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > b[i + 1]) {
            max_diff += a[i] - b[i + 1];
        }
    }
    max_diff += a[n - 1];

    cout << max_diff << "\n";
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