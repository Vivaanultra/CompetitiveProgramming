#include <bits/stdc++.h>
using namespace std;

// Function to solve a single test case
void solve() {
    int n;
    cin >> n;

    // We construct a permutation that allows for the maximum number of shrink operations (n-2).
    // The permutation [1, n, n-1, n-2, ..., 3, 2] achieves this.
    //
    // How it works:
    // 1. Initially, 'n' is between '1' and 'n-1'. Since 1 < n > n-1, 'n' can be removed.
    //    Array becomes: [1, n-1, n-2, ..., 2]
    // 2. Now, 'n-1' is between '1' and 'n-2'. Since 1 < n-1 > n-2, 'n-1' can be removed.
    //    Array becomes: [1, n-2, n-3, ..., 2]
    // 3. This continues until we are left with [1, 3, 2].
    // 4. '3' is between '1' and '2'. Since 1 < 3 > 2, '3' can be removed.
    // 5. The final array is [1, 2], and we have performed n-2 operations.

    // Print the first element '1'
    cout << 1 << " ";

    // Print numbers from 'n' down to '3'
    for (int i = n; i >= 3; --i) {
        cout << i << " ";
    }

    // Print the last element '2'
    cout << 2 << "\n";
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