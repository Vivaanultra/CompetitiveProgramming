#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = stoi(s);

    for (int k = 0; k <= 100; ++k) {
        if (k * k == n) {
            // We found the sum `k`. We need a and b where a+b=k.
            // The simplest choice is a=k and b=0.
            cout << k << " " << 0 << "\n";
            return;
        }
    }

    // If the loop finishes, no solution was found.
    cout << -1 << "\n";
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