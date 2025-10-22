#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> valid_indices_prefix_count(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        valid_indices_prefix_count[i] = valid_indices_prefix_count[i - 1];
        if (a[i - 1] < i) {
            valid_indices_prefix_count[i]++;
        }
    }

    long long total_pairs = 0;
    for (int j = 1; j <= n; ++j) {
        if (a[j - 1] < j) {
            long long limit = a[j - 1];
            if (limit > 0) {
                total_pairs += valid_indices_prefix_count[limit - 1];
            }
        }
    }
    cout << total_pairs << "\n";
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