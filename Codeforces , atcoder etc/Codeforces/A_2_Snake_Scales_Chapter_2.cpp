#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    long long cost;
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.cost < b.cost;
}

struct DSU {
    vector<int> parent;
    vector<int> sz;
    int platform_count;
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        sz.assign(n + 1, 1);
        sz[0] = 0; // Ground doesn't count as a platform
        platform_count = 0;
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            if (sz[root_i] < sz[root_j])
                swap(root_i, root_j);
            parent[root_j] = root_i;
            sz[root_i] += sz[root_j];
            if (root_i == find(0)) {
                 platform_count = sz[root_i];
            } else if (root_j == find(0)) {
                 platform_count = sz[root_j];
            }
        }
    }
};

void solve(int case_num) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<Edge> edges;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        edges.push_back({0, i + 1, (long long)a[i]});
        if (i > 0) {
            edges.push_back({i, i + 1, (long long)abs(a[i] - a[i - 1])});
        }
    }

    sort(edges.begin(), edges.end(), compareEdges);

    DSU dsu(n);
    long long ans = 0;

    for (const auto& edge : edges) {
        dsu.unite(edge.u, edge.v);
        if (dsu.platform_count == n) {
            ans = edge.cost;
            break;
        }
    }
    
    cout << "Case #" << case_num << ": " << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve(i);
    }
    return 0;
}