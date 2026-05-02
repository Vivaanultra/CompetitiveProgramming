#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int diff_count = 0;
    int last_diff_idx = -1;

    // Check for differences
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            diff_count++;
            last_diff_idx = i; // Store 0-based index
        }
    }

    if (diff_count % 2 == 0) {
        cout << "Tie" << "\n";
    } else {
        // last_diff_idx is 0-based.
        // Even indices (0, 2, 4...) are 1st, 3rd, 5th turns -> Odd turns (Ajisai)
        // Odd indices (1, 3, 5...) are 2nd, 4th, 6th turns -> Even turns (Mai)
        if (last_diff_idx % 2 == 0) {
            cout << "Ajisai" << "\n";
        } else {
            cout << "Mai" << "\n";
        }
    }
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