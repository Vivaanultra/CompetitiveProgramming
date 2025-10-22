#include <bits/stdc++.h>

using namespace std;

// Function to solve a single test case
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    // Vector to store the sequence of operations
    vector<pair<int, int>> ops;

    // Phase 1: Ensure a[i] < b[i] for all i.
    // If a[i] > b[i], we perform a type 3 swap.
    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) {
            swap(a[i], b[i]);
            // Record operation (3, i+1) using 1-based indexing.
            ops.push_back({3, i + 1});
        }
    }

    // Phase 2: Sort both arrays a and b independently using Bubble Sort.
    // This corresponds to type 1 and type 2 swaps.
    // We run n passes to guarantee both arrays are sorted.
    for (int pass = 0; pass < n; ++pass) {
        for (int i = 0; i < n - 1; ++i) {
            // Swap adjacent elements in 'a' if they are in the wrong order.
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                // Record operation (1, i+1) using 1-based indexing.
                ops.push_back({1, i + 1});
            }
            // Swap adjacent elements in 'b' if they are in the wrong order.
            if (b[i] > b[i + 1]) {
                swap(b[i], b[i + 1]);
                // Record operation (2, i+1) using 1-based indexing.
                ops.push_back({2, i + 1});
            }
        }
    }

    // Output the total number of operations.
    cout << ops.size() << "\n";
    // Output each recorded operation.
    for (const auto& op : ops) {
        cout << op.first << " " << op.second << "\n";
    }
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