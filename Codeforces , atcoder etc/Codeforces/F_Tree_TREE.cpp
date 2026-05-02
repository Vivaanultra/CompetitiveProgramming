#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<int>> adj;
vector<int> sz;
int n, k;

void dfs(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
}

void solve() {
    cin >> n >> k;
    adj.assign(n + 1, vector<int>());
    sz.assign(n + 1, 0);
    
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    ll ans = n; 

    
    for (int i = 2; i <= n; ++i) {
        int s = sz[i];       
        int rem = n - s;     

        
        
        if (s >= k) {
            ans += rem;
        }

        
        
        if (rem >= k) {
            ans += s;
        }
    }

    cout << ans << "\n";
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