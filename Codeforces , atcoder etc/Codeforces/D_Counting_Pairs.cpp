#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    long long x, y;
    cin >> n >> x >> y;
    vector<long long> a(n);
    long long total_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_sum += a[i];
    }

    sort(a.begin(), a.end());

    long long interesting_pairs = 0;
    long long lower_sum = total_sum - y;
    long long upper_sum = total_sum - x;

    for (int i = 0; i < n; ++i) {
        long long min_partner = lower_sum - a[i];
        long long max_partner = upper_sum - a[i];

        auto it_low = lower_bound(a.begin() + i + 1, a.end(), min_partner);
        auto it_high = upper_bound(a.begin() + i + 1, a.end(), max_partner);
        
        interesting_pairs += distance(it_low, it_high);
    }

    cout << interesting_pairs << "\n";
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