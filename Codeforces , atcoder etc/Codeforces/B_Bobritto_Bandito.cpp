#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, l, r;
    cin >> n >> m >> l >> r;

    // We have 'm' spreads to use.
    // First, determine how many of those spreads go to the right.
    // It's the smaller of the days we have (m) and the final right boundary (r).
    int right_spreads = min(m, r);

    // The rest of the spreads must go to the left.
    int left_spreads = m - right_spreads;

    // The new segment is defined by the number of spreads in each direction.
    int new_l = -left_spreads;
    int new_r = right_spreads;

    cout << new_l << " " << new_r << "\n";
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