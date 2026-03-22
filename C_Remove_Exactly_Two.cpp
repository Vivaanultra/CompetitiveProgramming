#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> deg(n + 1, 0);
    vector<vector<int>> adj(n + 1);
    vector<pair<int, int>> edges;
    
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v});
    }

    for(int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    int ans = 0;

    for(auto& e : edges) {
        ans = max(ans, deg[e.first] + deg[e.second] - 2);
    }

    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    sort(p.begin(), p.end(), [&](int a, int b) {
        return deg[a] > deg[b];
    });

    for(int i = 0; i < n; i++) {
        int u = p[i];
        for(int j = 0; j < n; j++) {
            if (i == j) continue;
            int v = p[j];
            
            if (deg[u] + deg[v] - 1 <= ans) {
                break; 
            }
            
            bool is_connected = binary_search(adj[u].begin(), adj[u].end(), v);
            
            if (!is_connected) {
                ans = max(ans, deg[u] + deg[v] - 1);
                break;
            }
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}