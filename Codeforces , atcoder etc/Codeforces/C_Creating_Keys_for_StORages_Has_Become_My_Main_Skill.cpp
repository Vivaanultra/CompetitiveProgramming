#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long x;
    cin >> n >> x;

    if (n == 1) {
        cout << x << "\n";
        return;
    }

    // prefix_or[i] will store 0 | 1 | ... | i
    vector<long long> prefix_or(n, 0);
    prefix_or[0] = 0;
    for (int i = 1; i < n; ++i) {
        prefix_or[i] = prefix_or[i - 1] | i;
    }

    // Find the maximum possible MEX.
    // A MEX of m is possible only if (0 | 1 | ... | m-1) is a "bitwise subset" of x.
    // Let's find the largest m <= n for which this necessary condition holds.
    int m_opt = 0;
    for (int m = 1; m <= n; ++m) {
        if ((prefix_or[m - 1] | x) == x) {
            m_opt = m;
        } else {
            // Since prefix_or is non-decreasing, the condition will fail for all larger m.
            break;
        }
    }
    
    int max_mex;
    // If m_opt is n, it's a special case.
    // We can only achieve MEX=n if the OR sum of {0..n-1} is exactly x.
    if (m_opt == n && prefix_or[n - 1] != x) {
        // We can't achieve MEX=n, but MEX=n-1 is possible because
        // (prefix_or[n-1]|x)==x implies (prefix_or[n-2]|x)==x.
        max_mex = n - 1;
    } else {
        max_mex = m_opt;
    }

    // Now construct the array for the determined max_mex.
    if (max_mex == n) {
        // This implies prefix_or[n-1] == x.
        for (int i = 0; i < n; ++i) {
            cout << i << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
    } else { // max_mex < n
        long long or_sum_of_mex_set = (max_mex > 0) ? prefix_or[max_mex - 1] : 0;
        long long extra_val = or_sum_of_mex_set ^ x;

        for (int i = 0; i < max_mex; ++i) {
            cout << i << " ";
        }
        cout << extra_val;
        for (int i = 0; i < n - max_mex - 1; ++i) {
            cout << " " << 0;
        }
        cout << "\n";
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