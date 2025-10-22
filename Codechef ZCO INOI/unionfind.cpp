#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
    vector<int> parent, sz;
public:
    UnionFind(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        sz.assign(n, 1);
    }

    int findSet(int i) {
        return (parent[i] == i) ? i : (parent[i] = findSet(parent[i]));
    }

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j) {
        int x = findSet(i), y = findSet(j);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        parent[y] = x;
        sz[x] += sz[y];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    UnionFind uf(N);

    while (Q--) {
        char op;
        int a, b;
        cin >> op >> a >> b;
        if (op == '=') {
            uf.unionSet(a, b);
        } else {
            cout << (uf.isSameSet(a, b) ? "yes\n" : "no\n");
        }
    }
    return 0;
}
