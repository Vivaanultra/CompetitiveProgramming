#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<long long> a(n), b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    vector<long long> prefix_a(n + 1, 0);
    vector<long long> prefix_b(m + 1, 0);
    for (int i = 0; i < n; ++i) prefix_a[i + 1] = prefix_a[i] + a[i];
    for (int i = 0; i < m; ++i) prefix_b[i + 1] = prefix_b[i] + b[i];

    vector<int> ideal_v(n + m + 1, 0);
    int ptr_a = 0, ptr_b = 0;
    for (int z = 1; z <= n + m; ++z) {
        ideal_v[z] = ideal_v[z - 1];
        if (ptr_a < n && (ptr_b == m || a[ptr_a] > b[ptr_b])) {
            ideal_v[z]++;
            ptr_a++;
        } else {
            ptr_b++;
        }
    }

    for (int i = 0; i < q; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        
        int v_star = ideal_v[z];
        
        int v_low = max(0, z - y);
        int v_high = min(z, x);

        int v_opt = max(v_low, min(v_high, v_star));

        long long total_sum = prefix_a[v_opt] + prefix_b[z - v_opt];
        cout << total_sum << "\n";
    }
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