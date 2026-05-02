#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long a;
    cin >> n >> a;
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        long long v;
        cin >> v;
        if (v < a) l++;
        if (v > a) r++;
    }
    if (l > r) cout << a - 1 << endl;
    else cout << a + 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}