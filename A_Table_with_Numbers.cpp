#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, h, l;
    cin >> n >> h >> l;
    vector<int> a(n);
    int both = 0, rows = 0, cols = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        bool r = (a[i] <= h);
        bool c = (a[i] <= l);
        if (r && c) both++;
        else if (r) rows++;
        else if (c) cols++;
    }

    int ans = min(rows, cols);
    int rem = abs(rows - cols);
    
    int use_both = min(rem, both);
    ans += use_both;
    both -= use_both;
    
    ans += both / 2;
    
    cout << ans << "\n";
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