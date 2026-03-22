#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    bool has_zero = false;
    bool adj_zeros = false;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) has_zero = true;
        // Check for adjacent zeros
        if (i > 0 && a[i] == 0 && a[i-1] == 0) {
            adj_zeros = true;
        }
    }

    // If no one reports a loss, or if two adjacent players report losses, it's a lie.
    if (!has_zero || adj_zeros) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    // Optimization for faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}