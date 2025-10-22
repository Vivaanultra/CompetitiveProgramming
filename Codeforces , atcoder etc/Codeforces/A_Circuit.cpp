#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int ones = 0;
    for (int i = 0; i < 2 * n; ++i) {
        int state;
        cin >> state;
        if (state == 1) {
            ones++;
        }
    }

    int zeros = 2 * n - ones;

    int max_on = min(ones, zeros);

    int max_guaranteed_off = (ones / 2) + (zeros / 2);
    int min_on = n - max_guaranteed_off;

    cout << min_on << " " << max_on << endl;
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