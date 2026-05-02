#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // max_sums[len] stores the maximum sum of a contiguous subarray of length 'len'
    // Initialize with a very small number because values can be negative
    vector<long long> max_sums(n + 1, -1e18);
    max_sums[0] = 0; // Empty subarray has sum 0

    // Pre-calculate max sum for every possible length
    for (int i = 0; i < n; i++) {
        long long current_sum = 0;
        for (int j = i; j < n; j++) {
            current_sum += a[j];
            int len = j - i + 1;
            max_sums[len] = max(max_sums[len], current_sum);
        }
    }

    // Calculate the answer for each k from 0 to n
    for (int k = 0; k <= n; k++) {
        long long best_ans = 0;
        for (int len = 0; len <= n; len++) {
            // We can add x to at most min(k, len) elements in the subarray
            long long current_val = max_sums[len] + (long long)min(k, len) * x;
            best_ans = max(best_ans, current_val);
        }
        cout << best_ans << (k == n ? "" : " ");
    }
    cout << endl;
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