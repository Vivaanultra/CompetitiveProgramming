#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    long long s;
    cin >> n >> s;

    long long total_sum = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_sum += a[i];
    }

    // If the target sum `s` is less than the minimum possible sum Alice can achieve,
    // then Bob can arrange the array in any way, and Alice will fail.
    if (s < total_sum) {
        // We can output any valid rearrangement. The original is fine.
        for (int i = 0; i < n; ++i) {
            cout << a[i] << (i == n - 1 ? "" : " ");
        }
        cout << endl;
    } else {
        // If s >= total_sum, Alice can always find a path, so Bob can't win.
        cout << -1 << endl;
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