#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n+1);
        vector<int> indeg(n+1, 0);

        for (int i = 0; i < n-1; ++i) {
            int u, v;
            long long x, y;
            cin >> u >> v >> x >> y;
            // choose orientation that yields the larger contribution
            if (x > y) {
                // want p[u] > p[v], so u should come before v in "bigger->smaller" order
                g[u].push_back(v);
                indeg[v]++;
            } else {
                // want p[v] > p[u] (or x==y doesn't matter)
                g[v].push_back(u);
                indeg[u]++;
            }
        }

        // Kahn's algorithm for topological sort
        queue<int> q;
        for (int i = 1; i <= n; ++i) if (indeg[i] == 0) q.push(i);

        vector<int> topo;
        topo.reserve(n);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            topo.push_back(u);
            for (int w : g[u]) {
                if (--indeg[w] == 0) q.push(w);
            }
        }

        // topo should contain all n nodes
        vector<int> p(n+1);
        int cur = n;
        for (int node : topo) {
            p[node] = cur--;
        }

        for (int i = 1; i <= n; ++i) {
            if (i > 1) cout << ' ';
            cout << p[i];
        }
        cout << '\n';
    }
    return 0;
}
