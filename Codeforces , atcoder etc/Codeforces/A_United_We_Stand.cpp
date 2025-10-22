#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    if (a[0] == a[n - 1]) {
        cout << -1 << "\n";
        return;
    }

    int first_diff_idx = -1;
    for (int i = 1; i < n; ++i) {
        if (a[i] > a[0]) {
            first_diff_idx = i;
            break;
        }
    }

    int lb = first_diff_idx;
    int lc = n - first_diff_idx;

    cout << lb << " " << lc << "\n";
    for (int i = 0; i < lb; ++i) {
        cout << a[i] << (i == lb - 1 ? "" : " ");
    }
    cout << "\n";
    for (int i = lb; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
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