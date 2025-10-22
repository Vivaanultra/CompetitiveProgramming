#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    // Store pairs of {value, original_index} to sort by value
    vector<pair<int, int>> b_pairs(n);
    for (int i = 0; i < n; ++i) {
        cin >> b_pairs[i].first;
        b_pairs[i].second = i;
    }

    sort(b_pairs.begin(), b_pairs.end());

    // --- Pass 1: Check for possibility ---
    bool possible = true;
    for (int i = 0; i < n; ) {
        int v = b_pairs[i].first;
        int j = i;
        // Find the end of the block of this value v
        while (j < n && b_pairs[j].first == v) {
            j++;
        }
        int count = j - i;
        if (count % v != 0) {
            possible = false;
            break;
        }
        i = j;
    }

    if (!possible) {
        cout << -1 << "\n";
        return;
    }

    // --- Pass 2: Construct the answer array 'a' ---
    vector<int> a(n);
    int current_val_for_a = 0;
    for (int i = 0; i < n; ) {
        int v = b_pairs[i].first;
        int j = i;
        while (j < n && b_pairs[j].first == v) {
            j++;
        }
        int count = j - i;
        
        // Iterate through the block of 'c' indices
        for (int k = 0; k < count; ++k) {
            // Every 'v' elements, we get a new value for 'a'
            if (k % v == 0) {
                current_val_for_a++;
            }
            int original_idx = b_pairs[i + k].second;
            a[original_idx] = current_val_for_a;
        }
        i = j;
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : " ");
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