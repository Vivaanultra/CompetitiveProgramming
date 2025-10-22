#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int hikes = 0;
    int i = 0;
    while (i <= n - k) {
        bool ok = true;
        for (int j = 0; j < k; ++j) {
            if (a[i + j] == 1) {
                ok = false;
                i = i + j + 1;
                break;
            }
        }
        if (ok) {
            hikes++;
            i += k + 1;
        }
    }
    cout << hikes << endl;
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