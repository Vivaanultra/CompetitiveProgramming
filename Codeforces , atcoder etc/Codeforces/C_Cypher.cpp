#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        string moves;
        cin >> moves;

        int current_val = a[i];
        for (char move : moves) {
            if (move == 'U') {
                // Reverse an Up move with a Down move
                current_val = (current_val - 1 + 10) % 10;
            } else {
                // Reverse a Down move with an Up move
                current_val = (current_val + 1) % 10;
            }
        }
        cout << current_val << " ";
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