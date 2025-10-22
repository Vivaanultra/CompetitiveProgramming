#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> freq(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (val <= n) {
            freq[val]++;
        }
    }

    int missing_count = 0;
    for (int i = 0; i < k; ++i) {
        if (freq[i] == 0) {
            missing_count++;
        }
    }

    int k_count = freq[k];

    cout << max(missing_count, k_count) << "\n";
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