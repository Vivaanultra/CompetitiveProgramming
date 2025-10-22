#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    vector<int> degree(n + 1, 0);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    if (n <= 2) {
        cout << 0 << "\n";
        return;
    }

    int total_leaves = 0;
    vector<bool> is_leaf(n + 1, false);
    for (int i = 1; i <= n; ++i) {
        if (degree[i] == 1) {
            total_leaves++;
            is_leaf[i] = true;
        }
    }

    int min_ops = n;
    for (int i = 1; i <= n; ++i) {
        int discount = 0;
        if (is_leaf[i]) {
            discount++;
        }
        for (int neighbor : adj[i]) {
            if (is_leaf[neighbor]) {
                discount++;
            }
        }
        min_ops = min(min_ops, total_leaves - discount);
    }
    cout << min_ops << "\n";
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