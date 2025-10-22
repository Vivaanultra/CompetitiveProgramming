#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;

    // Use vectors for pre-computation, ensuring 64-bit integers for sums.
    vector<long long> max_reqs(n);
    vector<long long> prefix_sums(n);

    long long current_max = 0;
    long long current_sum = 0;

    for (int i = 0; i < n; ++i) {
        long long step_height;
        cin >> step_height;
        current_max = max(current_max, step_height);
        current_sum += step_height;
        max_reqs[i] = current_max;
        prefix_sums[i] = current_sum;
    }

    // Process all queries
    for (int i = 0; i < q; ++i) {
        long long k;
        cin >> k;

        // upper_bound finds the first element in max_reqs > k.
        // The distance from the beginning gives us the index.
        auto it = upper_bound(max_reqs.begin(), max_reqs.end(), k);
        int idx = it - max_reqs.begin();

        if (idx == 0) {
            // If the first element is already greater than k, he can't climb any steps.
            cout << 0 << " ";
        } else {
            // Otherwise, the answer is the cumulative sum at the previous index.
            cout << prefix_sums[idx - 1] << " ";
        }
    }
    cout << endl;
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}