#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> max_indices(1001, 0);
    for (int i = 1; i <= n; ++i) {
        int val;
        cin >> val;
        max_indices[val] = i;
    }

    int max_sum = -1;

    for (int i = 1; i <= 1000; ++i) {
        if (max_indices[i] == 0) continue;

        for (int j = 1; j <= 1000; ++j) {
            if (max_indices[j] == 0) continue;

            if (gcd(i, j) == 1) {
                max_sum = max(max_sum, max_indices[i] + max_indices[j]);
            }
        }
    }
    cout << max_sum << endl;
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