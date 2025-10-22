#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int zeros = 0;
    int ones = 0;
    for (char c : s) {
        if (c == '0') {
            zeros++;
        } else {
            ones++;
        }
    }

    int bad_pairs_needed = (n / 2) - k;

    if (zeros < bad_pairs_needed || ones < bad_pairs_needed) {
        cout << "NO\n";
        return;
    }

    int rem_zeros = zeros - bad_pairs_needed;
    int rem_ones = ones - bad_pairs_needed;

    if (rem_zeros % 2 != 0 || rem_ones % 2 != 0) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
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