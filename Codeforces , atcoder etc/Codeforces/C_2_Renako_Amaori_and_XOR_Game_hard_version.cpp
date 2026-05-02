#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int total_diff = 0;
    for (int i = 0; i < n; i++) {
        total_diff ^= (a[i] ^ b[i]);
    }

    if (total_diff == 0) {
        cout << "Tie" << "\n";
        return;
    }

    // Find the Most Significant Bit (MSB) where the total scores differ.
    // __builtin_clz(x) returns the number of leading zeros.
    // 31 - __builtin_clz(x) gives the index of the MSB (0-indexed) for 32-bit int.
    int msb_pos = 31 - __builtin_clz(total_diff);
    int msb_val = 1 << msb_pos;

    // Find the last index (largest index) that affects this bit.
    int last_idx = -1;
    for (int i = n - 1; i >= 0; i--) {
        // Check if a[i] and b[i] differ at the MSB position
        if ((a[i] ^ b[i]) & msb_val) {
            last_idx = i;
            break;
        }
    }

    // Turns are 1-based in problem, 0-based in code.
    // Turn 1 (Index 0) -> Ajisai
    // Turn 2 (Index 1) -> Mai
    // Turn 3 (Index 2) -> Ajisai
    // Even indices are Ajisai, Odd indices are Mai.
    if (last_idx % 2 == 0) {
        cout << "Ajisai" << "\n";
    } else {
        cout << "Mai" << "\n";
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