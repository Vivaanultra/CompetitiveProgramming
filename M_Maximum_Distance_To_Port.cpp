#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void solve() {
    int n, m, k;
    if (!(cin >> n >> m >> k)) return;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // BFS from City 1 (Port)
    vector<int> dist(n + 1, -1);
    queue<int> q;

    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    // Compute max distance for each product type
    vector<int> result(k + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (dist[i] != -1) { // Should always be reachable per problem statement
            result[a[i]] = max(result[a[i]], dist[i]);
        }
    }

    // Output results
    for (int i = 1; i <= k; i++) {
        cout << result[i] << (i == k ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}