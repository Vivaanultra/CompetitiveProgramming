#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// Standard DSU structure for efficient component management
struct DSU {
    vector<int> parent;
    int num_components;

    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0); // Fill with 0, 1, 2...
        num_components = n;
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]); // Path compression
    }

    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            num_components--;
            return true;
        }
        return false;
    }
};

void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    // We store edges of F to process later
    vector<pair<int, int>> f_edges(m1);
    for (int i = 0; i < m1; ++i) {
        cin >> f_edges[i].first >> f_edges[i].second;
    }

    // DSU for Graph G
    // We use this to determine the "target" connected components
    DSU dsu_g(n);
    for (int i = 0; i < m2; ++i) {
        int u, v;
        cin >> u >> v;
        dsu_g.unite(u, v);
    }

    // DSU for Graph F (modified)
    // This will track the components of F after we remove "bad" edges
    DSU dsu_f(n);
    
    int remove_ops = 0;

    for (auto& edge : f_edges) {
        int u = edge.first;
        int v = edge.second;

        // CRITICAL LOGIC:
        // Check if u and v are in the SAME component in the target graph G.
        if (dsu_g.find(u) != dsu_g.find(v)) {
            // If they are different in G, they MUST NOT be connected in F.
            // This edge violates the condition, so we remove it.
            remove_ops++;
        } else {
            // If they are the same in G, this edge is valid/useful.
            // We keep it and build the F' components.
            dsu_f.unite(u, v);
        }
    }

    // Calculate Additions:
    // We currently have dsu_f.num_components.
    // We want to reach dsu_g.num_components.
    // Every edge addition reduces the component count by exactly 1.
    int add_ops = dsu_f.num_components - dsu_g.num_components;

    cout << remove_ops + add_ops << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}