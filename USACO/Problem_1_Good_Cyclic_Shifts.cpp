#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    long long f = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        f += abs(p[i] - i);
    }
    f /= 2;

    long long inv = 0;
    vector<int> bit(n + 1, 0);
    auto add = [&](int idx, int val) {
        for (; idx <= n; idx += idx & -idx) bit[idx] += val;
    };
    auto query = [&](int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) sum += bit[idx];
        return sum;
    };

    for (int i = 1; i <= n; ++i) {
        inv += query(n) - query(p[i]);
        add(p[i], 1);
    }

    long long e = inv - f;
    vector<int> inc_c(2 * n + 5, 0);
    vector<int> dec_c(2 * n + 5, 0);
    int c = 0;

    for (int i = 1; i <= n; ++i) {
        int v = p[i];
        if (v > i) {
            c++;
            dec_c[v - i]++;
        }
        int swrap = n - i + 1;
        if (v > 1) {
            inc_c[swrap]++;
            dec_c[swrap + v - 1]++;
        }
    }

    vector<int> ans;
    if (e == 0) ans.push_back(0);

    for (int s = 1; s < n; ++s) {
        int x = p[n - s + 1];
        e = e + x - n + c;
        c = c + inc_c[s] - dec_c[s];
        if (e == 0) ans.push_back(s);
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << (i + 1 == ans.size() ? "" : " ");
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