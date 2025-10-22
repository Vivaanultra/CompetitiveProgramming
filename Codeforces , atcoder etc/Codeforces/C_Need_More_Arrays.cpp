#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n == 0) {
        cout << 0 << "\n";
        return;
    }

    int groups = 0;
    int i = n - 1;
    while (i >= 0) {
        groups++;
        // Find the end of the current consecutive block
        int current_val = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] == current_val) {
            j--;
        }
        // Now a[j] < current_val
        int next_val_needed = current_val - 1;
        if (j >= 0 && a[j] == next_val_needed) {
            // We found a consecutive number, continue the block
            i = j;
            while(i >= 0 && a[i] >= next_val_needed) {
                i--;
            }

        } else {
            // No consecutive number, this group ends.
            // Move to the element before this block.
            i = j;
        }
    }

    cout << groups << "\n";
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