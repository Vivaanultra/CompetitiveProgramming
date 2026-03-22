#include <bits/stdc++.h>
using namespace std;

const long long INF = 2e18 + 7;

long long A[200005];
long long tree_seg[800005];

long long safe_mul(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    if (a > INF / b) return INF;
    return a * b;
}

void build(int node, int start, int end) {
    if (start > end) return;
    if (start == end) {
        tree_seg[node] = (A[start] + A[start - 1] - 1) / A[start - 1];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree_seg[node] = safe_mul(tree_seg[2 * node], tree_seg[2 * node + 1]);
}

void update(int node, int start, int end, int idx) {
    if (start > end) return;
    if (start == end) {
        tree_seg[node] = (A[start] + A[start - 1] - 1) / A[start - 1];
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid) {
        update(2 * node, start, mid, idx);
    } else {
        update(2 * node + 1, mid + 1, end, idx);
    }
    tree_seg[node] = safe_mul(tree_seg[2 * node], tree_seg[2 * node + 1]);
}

long long query(int node, int start, int end, int l, int r) {
    if (start > end || l > end || r < start) return 1;
    if (l <= start && end <= r) return tree_seg[node];
    int mid = (start + end) / 2;
    long long p1 = query(2 * node, start, mid, l, r);
    long long p2 = query(2 * node + 1, mid + 1, end, l, r);
    return safe_mul(p1, p2);
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    
    if (n > 1) {
        build(1, 2, n);
    }
    
    int q;
    if (!(cin >> q)) return;
    while (q--) {
        int i;
        long long v, t;
        cin >> i >> v >> t;
        
        A[i] = v;
        if (n > 1) {
            if (i > 1) update(1, 2, n, i);
            if (i < n) update(1, 2, n, i + 1);
        }
        
        long long prod = 1;
        if (n > 1) {
            prod = query(1, 2, n, 2, n);
        }
        
        long long CN = safe_mul(A[1] + 1, prod);
        long long SN = CN;
        
        if (CN < INF) {
            SN = CN + n - 1;
        } else {
            SN = INF;
        }
        
        if (t < SN) {
            cout << 0 << "\n";
        } else {
            long long dumps = (t - SN) / CN + 1;
            unsigned long long ans = (unsigned long long)dumps * A[n];
            cout << ans << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}