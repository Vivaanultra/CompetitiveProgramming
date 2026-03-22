#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    // Frequency array to store count of each remainder (0 to k-1)
    vector<int> remainder_counts(k, 0);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        // Increment the count for this specific remainder
        remainder_counts[a[i] % k]++;
    }

    // Now, look for a number whose remainder appears exactly once
    for (int i = 0; i < n; ++i) {
        if (remainder_counts[a[i] % k] == 1) {
            cout << "YES" << "\n";
            // Output 1-based index
            cout << i + 1 << "\n";
            return;
        }
    }

    // If we finish the loop without returning, no unique remainder exists
    cout << "NO" << "\n";
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