#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> adj(n);
    vector<int> degree(n, 0);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    // Step 1 & 2: Find initial leaves and add them to the queue
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (degree[i] <= 1) {
            q.push(i);
        }
    }

    int remaining_nodes = n;
    
    // Step 3: Peel layer by layer for k rounds
    for (int round = 0; round < k; ++round) {
        // If the tree is empty or just a single edge, it will be gone after this
        if (q.empty()) {
            break;
        }

        int nodes_in_layer = q.size();
        remaining_nodes -= nodes_in_layer;

        for (int i = 0; i < nodes_in_layer; ++i) {
            int u = q.front();
            q.pop();
            degree[u] = -1; // Mark as removed

            for (int v : adj[u]) {
                if (degree[v] > 0) {
                    degree[v]--;
                    if (degree[v] == 1) {
                        q.push(v);
                    }
                }
            }
        }
    }

    // Step 4: Print the remainder
    cout << remaining_nodes << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        // Each test case in this problem has a blank line before it
        string blank;
        getline(cin, blank);
        solve();
    }

    return 0;
}