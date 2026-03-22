#include <bits/stdc++.h>
using namespace std;
#define I long long
I l[200005], r[200005], d[200005], s[200005];
int v[200005], n, m;
vector<pair<int, int>> g[200005];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> l[i];
    for (int i = 1; i <= n; ++i) cin >> r[i];
    for (int i = 1; i <= n; ++i) { g[i].clear(); v[i] = 0; }
    while (m--) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w}); g[v].push_back({u, w});
    }

    I ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (v[i]) continue;
        vector<int> c = {i}; v[i] = 1; s[i] = 1; d[i] = 0;
        vector<I> fix;
        int head = 0, bad = 0;

        while (head < c.size()) {
            int u = c[head++];
            for (auto& e : g[u]) {
                if (!v[e.first]) {
                    v[e.first] = 1; s[e.first] = -s[u]; d[e.first] = e.second - d[u];
                    c.push_back(e.first);
                } else {
                    I val = e.second - d[u] - d[e.first];
                    if (s[u] == -s[e.first]) { if (val) bad = 1; } 
                    else { if (val % 2) bad = 1; fix.push_back(val / s[u] / 2); }
                }
            }
        }
        
        if (!fix.empty()) {
            for (I x : fix) if (x != fix[0]) bad = 1;
            if (bad) { cout << "-1\n"; return; }
            for (int u : c) {
                I a = s[u] * fix[0] + d[u];
                if (a >= l[u] && a <= r[u]) ans++;
            }
        } else if (!bad) {
            map<I, int> ev;
            for (int u : c) {
                I L = (s[u] == 1) ? l[u] - d[u] : d[u] - r[u];
                I R = (s[u] == 1) ? r[u] - d[u] : d[u] - l[u];
                if (L <= R) ev[L]++, ev[R + 1]--;
            }
            int cur = 0, mx = 0;
            for (auto& p : ev) mx = max(mx, cur += p.second);
            ans += mx;
        } else { cout << "-1\n"; return; }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; while (t--) solve();
    return 0;
}