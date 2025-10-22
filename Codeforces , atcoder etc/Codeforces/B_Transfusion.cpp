#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long total_sum = 0;
    long long even_sum = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_sum += a[i];
        if (i % 2 == 0) {
            even_sum += a[i];
        }
    }

    if (total_sum % n != 0) {
        cout << "NO\n";
        return;
    }

    long long target = total_sum / n;
    long long odd_sum = total_sum - even_sum;

    int even_count = (n + 1) / 2;
    int odd_count = n / 2;

    if (even_sum == (long long)even_count * target && odd_sum == (long long)odd_count * target) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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