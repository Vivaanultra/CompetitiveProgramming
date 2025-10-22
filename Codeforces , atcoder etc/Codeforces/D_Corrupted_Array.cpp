#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> b(n + 2);
    for (int i = 0; i < n + 2; ++i) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());

    long long sum_first_n = 0;
    for (int i = 0; i < n; ++i) {
        sum_first_n += b[i];
    }

    if (sum_first_n == b[n]) {
        for (int i = 0; i < n; ++i) {
            cout << b[i] << " ";
        }
        cout << endl;
        return;
    }

    long long sum_first_n_plus_1 = sum_first_n + b[n];
    int found_idx = -1;
    for (int i = 0; i <= n; ++i) {
        if (sum_first_n_plus_1 - b[i] == b[n + 1]) {
            found_idx = i;
            break;
        }
    }

    if (found_idx != -1) {
        for (int i = 0; i <= n; ++i) {
            if (i == found_idx) continue;
            cout << b[i] << " ";
        }
        cout << endl;
        return;
    }

    cout << -1 << endl;
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