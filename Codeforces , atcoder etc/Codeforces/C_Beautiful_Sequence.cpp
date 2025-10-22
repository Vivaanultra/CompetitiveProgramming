#include <bits/stdc++.h>
using namespace std;

// This function solves a single test case.
void solve() {
    int n;
    cin >> n;
    
    // DP states:
    // c1: # of subsequences of the form [1]
    // c12: # of subsequences of the form [1, 2, ..., 2] (with >=1 two)
    // c123: # of beautiful subsequences [1, 2, ..., 2, 3]
    long long c1 = 0, c12 = 0, c123 = 0;
    long long MOD = 998244353;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        if (x == 1) {
            // A new '1' can start a new [1] subsequence.
            c1 = (c1 + 1) % MOD;
        } else if (x == 2) {
            // A '2' can extend any [1] to a [1, 2] or any [1, 2..2] to a longer one.
            // new_c12 = c12 (don't use current 2) + c12 (extend) + c1 (form new [1,2])
            c12 = (c12 * 2 + c1) % MOD;
        } else if (x == 3) {
            // A '3' can finalize any [1, 2...2] subsequence to make it beautiful.
            // Add the number of valid prefixes to the total count.
            c123 = (c123 + c12) % MOD;
        }
    }

    cout << c123 << endl;
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