#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, int> counts;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        counts[x]++;
    }

    long long ans = 0;
    int prev_count = 0;
    int prev_size = 0;

    for (auto const& [size, count] : counts) {
        // If the current size is not consecutive to the previous one,
        // all dolls of this size must start new sets.
        // Otherwise, only the excess dolls (more than the previous size)
        // must start new sets.
        if (size != prev_size + 1) {
            ans += count;
        } else {
            ans += max(0, count - prev_count);
        }
        prev_count = count;
        prev_size = size;
    }

    cout << ans << endl;
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
