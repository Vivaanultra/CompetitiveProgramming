#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

struct Solver {
    int n, m;
    vector<long long> a;
    vector<vector<int>> adj;
    
    
    vector<map<long long, int>> memo;

    
    int solve_path(int u, long long prev_val) {
        
        if (memo[u].count(prev_val)) {
            return memo[u][prev_val];
        }

        long long target = a[u] + prev_val;
        int count = 0;

        
        
        
        
        auto it = lower_bound(adj[u].begin(), adj[u].end(), target, 
            [&](int neighbor, long long val) {
                return a[neighbor] < val;
            });
        
        
        while (it != adj[u].end() && a[*it] == target) {
            int v = *it;
            
            
            int extensions = solve_path(v, a[u]);
            count = (count + 1 + extensions) % MOD;
            it++;
        }

        return memo[u][prev_val] = count;
    }

    void run() {
        cin >> n >> m;
        a.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        adj.assign(n + 1, vector<int>());
        vector<pair<int, int>> edges;
        edges.reserve(m);

        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            edges.push_back({u, v});
        }

        
        
        for (int i = 1; i <= n; ++i) {
            sort(adj[i].begin(), adj[i].end(), [&](int u_idx, int v_idx) {
                return a[u_idx] < a[v_idx];
            });
        }

        memo.assign(n + 1, map<long long, int>());
        long long total_paths = 0;

        
        for (const auto& edge : edges) {
            int u = edge.first;
            int v = edge.second;

            
            total_paths = (total_paths + 1) % MOD;

            
            
            total_paths = (total_paths + solve_path(v, a[u])) % MOD;
        }

        cout << total_paths << "\n";
    }
};

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        Solver s;
        s.run();
    }
    return 0;
}