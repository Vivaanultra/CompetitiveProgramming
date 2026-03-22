#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> q(n), r(n);
    for (int i = 0; i < n; i++) cin >> q[i];
    for (int i = 0; i < n; i++) cin >> r[i];

    // Transform problem to: (q[i]+1) * (r[j]+1) <= k+1
    for (int i = 0; i < n; i++) q[i]++;
    for (int i = 0; i < n; i++) r[i]++;
    k++;

    // Sort q descending (process largest/hardest first)
    sort(q.begin(), q.end(), greater<long long>());
    
    // Sort r ascending (to efficiently find valid candidates)
    sort(r.begin(), r.end());

    int ans = 0;
    int r_idx = 0;
    int pool = 0;

    for (int i = 0; i < n; i++) {
        long long val = q[i];
        if (val > k) continue; // Optimization: q[i] too large for any r >= 1 (transformed r >= 2)
        
        long long limit = k / val;

        // Add all r's that satisfy the condition for the current (and future) q
        while (r_idx < n && r[r_idx] <= limit) {
            pool++;
            r_idx++;
        }

        // Use one valid r if available
        if (pool > 0) {
            pool--;
            ans++;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}