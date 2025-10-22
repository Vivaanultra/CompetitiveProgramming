#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, j, k;
    cin >> n >> j >> k;
    vector<int> a(n);
    int our_strength = 0;
    bool is_strongest = true;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    our_strength = a[j - 1];

    for (int i = 0; i < n; ++i) {
        if (a[i] > our_strength) {
            is_strongest = false;
            break;
        }
    }

    if (is_strongest) {
        cout << "YES\n";
    } else {
        if (k >= 2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
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