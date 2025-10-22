#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << -1 << endl;
        return;
    }

    vector<int> p(n);
    p[0] = 1;

    for (int i = 1; i <= n / 2; ++i) {
        p[2 * i] = 2 * i;
        p[2 * i - 1] = 2 * i + 1;
    }
    
    // The previous code had a flaw. Let's write the correct one.
    vector<int> ans(n);
    ans[0] = 1;
    int k = (n+1)/2;
    for (int i = 1; i < k; ++i) {
        ans[i] = 2 * (i + 1) - 1;
    }
    for (int i = k; i < n; ++i) {
        ans[i] = 2 * (i - k + 1);
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << (i == n - 1 ? "" : " ");
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