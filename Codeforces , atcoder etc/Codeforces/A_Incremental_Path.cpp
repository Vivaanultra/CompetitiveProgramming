#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<ll> a(m);
        for (int i = 0; i < m; ++i) cin >> a[i];

        // parent[x] exists iff x is black; parent[x] = next candidate (first white >= that value)
        unordered_map<ll,ll> parent;
        parent.reserve((size_t)(m + n) * 2 + 10);

        auto find_next_white = [&](ll x) {
            // iterative find with path compression
            vector<ll> stk;
            while (true) {
                auto it = parent.find(x);
                if (it == parent.end()) break;
                stk.push_back(x);
                x = it->second;
            }
            for (ll v : stk) parent[v] = x;
            return x;
        };

        // mark initial black cells
        for (ll v : a) {
            if (parent.find(v) == parent.end()) {
                parent[v] = find_next_white(v + 1);
            }
        }

        // vis stores positions p_k[j]: after j commands for the last processed person.
        // We store p_0[0] = 1 initially (position after 0 commands).
        vector<ll> vis;
        vis.reserve(n + 5);
        vis.push_back(1); // p_0[0] = 1

        for (int i = 1; i <= n; ++i) {
            if (i == 1) {
                ll start = vis[0];
                ll x1;
                if (s[0] == 'A') x1 = start + 1;
                else x1 = find_next_white(start + 1);
                // build p_1: keep p_1[0]=1 (vis[0]) and push p_1[1]
                vis.push_back(x1);
                if (parent.find(x1) == parent.end()) parent[x1] = find_next_white(x1 + 1);
            } else {
                // start = position after i-2 commands (p_{i-1}[i-2])
                ll start = vis[i-2];
                ll x1, x2;
                // apply command (i-1)-th : s[i-2]
                if (s[i-2] == 'A') x1 = start + 1;
                else x1 = find_next_white(start + 1);
                // apply command i-th : s[i-1]
                if (s[i-1] == 'A') x2 = x1 + 1;
                else x2 = find_next_white(x1 + 1);

                // update vis to be p_i:
                // keep vis[0..i-3], set vis[i-1] = x1 (overwrite previous p_{i-1}[i-1])
                if ((int)vis.size() >= i) vis[i-1] = x1;
                else vis.push_back(x1); // happens when vis.size() == i-1 (i==2)
                vis.push_back(x2);

                if (parent.find(x2) == parent.end()) parent[x2] = find_next_white(x2 + 1);
            }
        }

        // final black cells are keys of parent
        vector<ll> ans;
        ans.reserve(parent.size());
        for (auto &kv : parent) ans.push_back(kv.first);
        sort(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for (size_t i = 0; i < ans.size(); ++i) {
            if (i) cout << ' ';
            cout << ans[i];
        }
        cout << '\n';
    }
    return 0;
}
