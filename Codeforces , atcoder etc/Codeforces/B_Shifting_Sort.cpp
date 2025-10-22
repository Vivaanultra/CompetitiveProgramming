#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // This vector will store the operations (l, r, d)
    vector<tuple<int, int, int>> operations;

    // Loop from the first to the second-to-last element
    for (int i = 0; i < n; ++i) {
        // Find the index of the minimum element in the subarray a[i...n-1]
        int min_val = a[i];
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < min_val) {
                min_val = a[j];
                min_idx = j;
            }
        }
        
        // If the minimum element is not already in the correct place
        if (min_idx != i) {
            int l = i + 1;
            int r = min_idx + 1;
            int d = min_idx - i;
            
            operations.emplace_back(l, r, d);

            // Perform the cyclic shift on the array `a`
            int temp = a[min_idx];
            for (int k = min_idx; k > i; --k) {
                a[k] = a[k - 1];
            }
            a[i] = temp;
        }
    }

    cout << operations.size() << endl;
    for (const auto& op : operations) {
        cout << get<0>(op) << " " << get<1>(op) << " " << get<2>(op) << endl;
    }
}

int main() {
    // It is currently Saturday, 11:34 PM in Mathura, India.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
