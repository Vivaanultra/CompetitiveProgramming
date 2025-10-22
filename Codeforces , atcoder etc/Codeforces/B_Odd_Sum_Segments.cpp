#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> odd_indices;
    for (int i = 1; i <= n; ++i) {
        int val;
        cin >> val;
        if (val % 2 != 0) {
            odd_indices.push_back(i);
        }
    }

    int odd_count = odd_indices.size();

    // Check the two necessary conditions:
    // 1. We must have at least k odd numbers.
    // 2. The parity of the number of odd numbers must match the parity of k.
    if (odd_count < k || odd_count % 2 != k % 2) {
        cout << "NO\n";
        return;
    }

    // If conditions are met, a solution is always possible.
    cout << "YES\n";
    // Print the indices of the first k-1 odd numbers as the boundaries.
    for (int i = 0; i < k - 1; ++i) {
        cout << odd_indices[i] << " ";
    }
    // The final boundary is always n.
    cout << n << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}