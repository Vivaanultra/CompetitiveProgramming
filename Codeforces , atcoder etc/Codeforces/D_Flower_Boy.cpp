#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    vector<long long> b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];

    int a_ptr = 0;
    int b_ptr = 0;
    while (a_ptr < n && b_ptr < m) {
        if (a[a_ptr] >= b[b_ptr]) {
            b_ptr++;
        }
        a_ptr++;
    }
    if (b_ptr == m) {
        cout << 0 << "\n";
        return;
    }

    vector<int> prefix_pos(m, -1);
    a_ptr = 0;
    b_ptr = 0;
    while (a_ptr < n && b_ptr < m) {
        if (a[a_ptr] >= b[b_ptr]) {
            prefix_pos[b_ptr] = a_ptr;
            b_ptr++;
        }
        a_ptr++;
    }

    vector<int> suffix_pos(m, -1);
    a_ptr = n - 1;
    b_ptr = m - 1;
    while (a_ptr >= 0 && b_ptr >= 0) {
        if (a[a_ptr] >= b[b_ptr]) {
            suffix_pos[b_ptr] = a_ptr;
            b_ptr--;
        }
        a_ptr--;
    }

    long long min_k = -1;

    auto update_min = [&](long long val) {
        if (min_k == -1 || val < min_k) {
            min_k = val;
        }
    };

    if (suffix_pos[1] != -1) {
        update_min(b[0]);
    }

    if (prefix_pos[m - 2] != -1) {
        update_min(b[m - 1]);
    }

    for (int i = 0; i < m - 2; ++i) {
        if (prefix_pos[i] != -1 && suffix_pos[i + 2] != -1 && prefix_pos[i] < suffix_pos[i + 2]) {
            update_min(b[i + 1]);
        }
    }

    cout << min_k << "\n";
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