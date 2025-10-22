#include <bits/stdc++.h>

using namespace std;

// Use long long for sums to prevent overflow, as danger values can be large.
using ll = long long;

// Adjacency list to represent the tree.
vector<vector<int>> adj;
// Vector to store the danger values 'a'.
vector<ll> a;
// DP vectors to store the computed threats.
// pos_threat[i] corresponds to the final answer for vertex i.
vector<ll> pos_threat;
vector<ll> neg_threat;

/**
 * @brief Performs DFS from the root to compute threats for all vertices.
 * @param u The current vertex.
 * @param p The parent of the current vertex.
 */
void dfs(int u, int p) {
    // For the parent p, get its pre-computed threat values.
    // For the root (p=0), parent threats are effectively 0.
    ll parent_pos_threat = 0;
    ll parent_neg_threat = 0;

    if (p != 0) {
        parent_pos_threat = pos_threat[p];
        parent_neg_threat = neg_threat[p];
    }

    // Apply the recurrence relations to compute threats for vertex u.
    // Note: a is 0-indexed, so we use a[u-1].
    pos_threat[u] = a[u - 1] + max(0LL, parent_neg_threat);
    neg_threat[u] = -a[u - 1] + max(0LL, parent_pos_threat);

    // Recursively call dfs for all children of u.
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
}

void solve() {
    int n;
    cin >> n;

    // Resize data structures for the current test case.
    a.assign(n, 0);
    adj.assign(n + 1, vector<int>());
    pos_threat.assign(n + 1, 0);
    neg_threat.assign(n + 1, 0);
    
    // Read danger values.
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Read edges and build the adjacency list.
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Start DFS from the root (vertex 1). Parent of root is 0.
    dfs(1, 0);

    // Output the computed threat for each vertex.
    for (int i = 1; i <= n; ++i) {
        cout << pos_threat[i] << " ";
    }
    cout << "\n";
}

int main() {
    // Fast I/O for competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}