#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    multiset<int> swords;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        swords.insert(a);
    }

    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<int> c(m);
    for (int i = 0; i < m; i++) cin >> c[i];

    vector<pair<int, int>> refunding, consuming;
    for (int i = 0; i < m; i++) {
        if (c[i] > 0) {
            refunding.push_back({b[i], c[i]});
        } else {
            consuming.push_back({b[i], c[i]});
        }
    }

    sort(refunding.begin(), refunding.end());
    sort(consuming.begin(), consuming.end());

    int ans = 0;

    for (auto p : refunding) {
        auto it = swords.lower_bound(p.first);
        if (it != swords.end()) {
            int val = *it;
            swords.erase(it);
            swords.insert(max(val, p.second));
            ans++;
        }
    }

    for (auto p : consuming) {
        auto it = swords.lower_bound(p.first);
        if (it != swords.end()) {
            swords.erase(it);
            ans++;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}