#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
bool is_marked[MAXN];
int n;

pair<int, int> bfs(int start_node) {
    vector<int> dist(n + 1, -1);
    queue<int> q;

    dist[start_node] = 0;
    q.push(start_node);

    int farthest_node = start_node;
    int max_dist = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (dist[u] > max_dist) {
            max_dist = dist[u];
            farthest_node = u;
        }

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    // Specifically find the farthest *marked* node
    int farthest_marked_node = -1;
    max_dist = -1;
    for(int i = 1; i <= n; ++i) {
        if(is_marked[i] && dist[i] > max_dist) {
            max_dist = dist[i];
            farthest_marked_node = i;
        }
    }
    
    return {farthest_marked_node, max_dist};
}

void solve() {
    int k;
    cin >> n >> k;

    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        is_marked[i] = false;
    }

    vector<int> marked_nodes(k);
    for (int i = 0; i < k; ++i) {
        cin >> marked_nodes[i];
        is_marked[marked_nodes[i]] = true;
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    pair<int, int> u_info = bfs(marked_nodes[0]);
    pair<int, int> v_info = bfs(u_info.first);
    
    int diameter = v_info.second;
    cout << (diameter + 1) / 2 << "\n";
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