#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> sz;

    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        sz.assign(n + 1, 1);
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void unite_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }

    DSU dsu(n);

    for (int i = 1; i <= n; ++i) {
        dsu.unite_sets(i, p[i]);
    }

    vector<bool> broken(n + 1, false);
    int broken_elements_count = 0;
    vector<int> ans;

    for (int i = 0; i < n; ++i) {
        int idx_to_zero = d[i];
        int root = dsu.find_set(idx_to_zero);
        if (!broken[root]) {
            broken_elements_count += dsu.sz[root];
            broken[root] = true;
        }
        ans.push_back(broken_elements_count);
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
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