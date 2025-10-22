#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    long long c, d;
    cin >> n >> c >> d;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());

    // Edge Case: Impossible
    if (a[0] * d < c) {
        cout << "Impossible" << endl;
        return;
    }
    
    // Edge Case: Infinity
    long long top_d_sum = 0;
    for (int i = 0; i < min((long long)n, d); ++i) {
        top_d_sum += a[i];
    }
    if (top_d_sum >= c) {
        cout << "Infinity" << endl;
        return;
    }

    vector<long long> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + a[i];
    }

    auto check = [&](long long k) {
        long long period = k + 1;
        long long num_periods = d / period;
        long long rem_days = d % period;
        
        long long total_sum = 0;
        long long period_sum = prefix_sum[min((long long)n, period)];
        
        total_sum += num_periods * period_sum;
        total_sum += prefix_sum[min((long long)n, rem_days)];
        
        return total_sum >= c;
    };

    // Binary Search for the answer k
    long long low = 0, high = d + 2, ans = 0;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
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