#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int tree[MAXN];
int n;

void update(int idx, int val) {
    for (; idx <= n + 1; idx += idx & -idx)
        tree[idx] = max(tree[idx], val);
}

int query(int idx) {
    int res = 0;
    for (; idx > 0; idx -= idx & -idx)
        res = max(res, tree[idx]);
    return res;
}

void solve() {
    cin >> n;
    vector<int> a(n + 1);
    vector<vector<int>> pos(n + 1);

    for (int i = 0; i <= n + 1; i++) tree[i] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        int v = a[i];
        if (v > n) continue;

        pos[v].push_back(i);

        if (pos[v].size() >= v) {
            int start_idx = pos[v][pos[v].size() - v];
            int prev_max = query(start_idx);
            update(i + 1, prev_max + v);
        }
    }
    cout << query(n + 1) << "\n";
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