#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
string colors;
int balanced_count;

// The DFS function returns the {white_count, black_count} for the subtree at `u`.
pair<int, int> dfs(int u) {
    // Initialize counts for the current node itself.
    int white_nodes = (colors[u - 1] == 'W');
    int black_nodes = (colors[u - 1] == 'B');

    // Get reports from all children.
    for (int v : adj[u]) {
        pair<int, int> child_counts = dfs(v);
        white_nodes += child_counts.first;
        black_nodes += child_counts.second;
    }

    // After gathering all info, check if this subtree is balanced.
    if (white_nodes == black_nodes) {
        balanced_count++;
    }

    // Send the report for this subtree up to the parent.
    return {white_nodes, black_nodes};
}

void solve() {
    int n;
    cin >> n;

    // Reset global state for the new test case.
    adj.assign(n + 1, vector<int>());
    balanced_count = 0;

    // Build the adjacency list from the parent array.
    for (int i = 2; i <= n; ++i) {
        int parent;
        cin >> parent;
        adj[parent].push_back(i);
    }
    cin >> colors;

    // Start the DFS from the root (vertex 1).
    dfs(1);

    cout << balanced_count << endl;
}

int main() {
    // It is currently Sunday, 6:40 PM in Mathura, India.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}