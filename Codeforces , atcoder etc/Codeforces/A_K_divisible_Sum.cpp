#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;

    // 1. Find the smallest sum 'S' such that S >= n and S is a multiple of k.
    // This is ceil(n/k) * k.
    long long min_sum = ((n + k - 1) / k) * k;

    // 2. The minimum possible maximum element is ceil(S / n).
    long long ans = (min_sum + n - 1) / n;

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