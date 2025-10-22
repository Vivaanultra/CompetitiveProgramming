#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int max_val = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        max_val = max(max_val, x);
    }
    cout << max_val << endl;
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