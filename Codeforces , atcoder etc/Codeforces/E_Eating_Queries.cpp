#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Step 1: Rank the candies from sweetest to least sweet
    sort(a.rbegin(), a.rend());

    // Step 2: Pre-calculate the running totals (prefix sums)
    vector<long long> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + a[i];
    }

    // Step 3: Answer each query
    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;

        // Handle the impossible case
        if (x > prefix_sum[n]) {
            cout << -1 << endl;
            continue;
        }

        // Use binary search (lower_bound) to find the minimum k
        // We are searching for the first prefix sum that is >= x
        auto it = lower_bound(prefix_sum.begin(), prefix_sum.end(), x);
        
        // The distance from the beginning of the array is the number of candies
        cout << (it - prefix_sum.begin()) << endl;
    }
}

int main() {
    // It is currently Sunday, 6:32 PM in Mathura, India.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}