#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int min_pos = -1, max_pos = -1;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == 1) {
            min_pos = i;
        }
        if (x == n) {
            max_pos = i;
        }
    }

    if (min_pos > max_pos) {
        swap(min_pos, max_pos);
    }

    // Case 1: Remove both from the left
    int res1 = max_pos + 1;

    // Case 2: Remove both from the right
    int res2 = n - min_pos;

    // Case 3: Remove one from left and one from right
    int res3 = (min_pos + 1) + (n - max_pos);

    cout << min({res1, res2, res3}) << endl;
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