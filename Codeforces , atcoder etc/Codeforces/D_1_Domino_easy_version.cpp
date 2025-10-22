#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, m, k;
    cin >> n >> m >> k;

    bool possible = true;

    // Condition set for the original n x m grid with k horizontal dominoes
    if (n % 2 == 0) {
        if (k % 2 != 0) {
            possible = false;
        }
    } else { // n is odd, so m must be even
        if (k < m / 2 || (k - m / 2) % 2 != 0) {
            possible = false;
        }
    }

    // Condition set for the rotated m x n grid
    // The number of "horizontal" dominoes in this view is v = (n * m / 2 - k)
    long long v = (n * m / 2) - k;
    if (m % 2 == 0) {
        if (v % 2 != 0) {
            possible = false;
        }
    } else { // m is odd, so n must be even
        if (v < n / 2 || (v - n / 2) % 2 != 0) {
            possible = false;
        }
    }
    
    // A special case: if m is odd, k must be >= m/2, but also v cannot be less than n/2.
    // k = n*m/2 - v. So k <= n*m/2 - n/2.
    // Let's check if k exceeds the max possible for that scenario.
    if (n % 2 == 1) { // n is odd, m is even
        // In the rotated view (m x n), the number of vertical dominoes is k.
        // The max number of horizontal dominoes is m*n/2. k cannot be greater than this.
        // This is already covered by the problem constraints. No extra check needed.
    }


    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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