#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    // Vector to store the permutation, using 1-based indexing.
    vector<int> p(2 * n + 1);

    // Read the entire n x n grid to consume the input,
    // but only store the values from the first and last rows.
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int val;
            cin >> val;
            // The first row gives us p[2] through p[n+1].
            if (i == 1) {
                p[i + j] = val;
            }
            // The last row gives us p[n+1] through p[2n].
            if (i == n) {
                p[i + j] = val;
            }
        }
    }

    // Now, p[2] through p[2n] are filled. We find p[1] using your summation method.
    
    // 1. Calculate the sum of the elements we found.
    long long sum_of_found = 0;
    for (int k = 2; k <= 2 * n; ++k) {
        sum_of_found += p[k];
    }
    
    // 2. Calculate the total sum of a permutation of 1 to 2n.
    // The formula is m*(m+1)/2, where m = 2n.
    long long total_sum = (long long)(2 * n) * (2 * n + 1) / 2;
    
    // 3. The missing element is the difference.
    p[1] = total_sum - sum_of_found;

    // Print the final reconstructed permutation.
    for (int k = 1; k <= 2 * n; ++k) {
        cout << p[k] << (k == 2 * n ? "" : " ");
    }
    cout << "\n";
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