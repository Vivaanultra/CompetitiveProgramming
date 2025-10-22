#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int total_and = -1; // -1 in two's complement is all 1s (identity for AND)
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_and &= a[i];
    }

    // Case 1: The minimum possible sum is greater than 0.
    // The only way to achieve this is with one group.
    if (total_and > 0) {
        cout << 1 << "\n";
        return;
    }

    // Case 2: The minimum possible sum is 0.
    // We need to find the max number of groups that each have an AND-sum of 0.
    int groups = 0;
    int current_group_and = -1;
    for (int x : a) {
        current_group_and &= x;
        // If the current group's AND becomes 0, we can make a cut.
        if (current_group_and == 0) {
            groups++;
            current_group_and = -1; // Reset for the next group.
        }
    }

    // The answer is the number of groups we made. If we couldn't make any cuts,
    // the answer is 1 (the whole array is one group with an AND-sum of 0).
    cout << max(1, groups) << "\n";
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