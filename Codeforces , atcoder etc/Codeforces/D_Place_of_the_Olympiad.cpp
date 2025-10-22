#include<bits/stdc++.h>

using namespace std;

bool is_possible(long long n, long long m, long long k, long long max_len) {
    if (max_len == 0) return false;
    long long desks_per_row = m / (max_len + 1) * max_len + min(m % (max_len + 1), max_len);
    return desks_per_row * n >= k;
}

void solve() {
    long long n, m, k;
    cin >> n >> m >> k;

    long long low = 1, high = m, ans = m;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (n * (m - (m / (mid + 1))) >= k) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
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