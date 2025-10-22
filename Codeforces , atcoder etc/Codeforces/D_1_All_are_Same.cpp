#include <bits/stdc++.h>

using namespace std;

// Standard GCD function
long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    bool all_same = true;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i > 0 && a[i] != a[0]) {
            all_same = false;
        }
    }

    // Handle the special case
    if (all_same) {
        cout << -1 << endl;
        return;
    }

    // Efficiently find the GCD of all differences
    long long min_val = a[0];
    for (int i = 1; i < n; ++i) {
        min_val = min(min_val, a[i]);
    }

    long long result_gcd = 0;
    for (int i = 0; i < n; ++i) {
        long long diff = a[i] - min_val;
        if (diff > 0) {
            if (result_gcd == 0) {
                result_gcd = diff;
            } else {
                result_gcd = gcd(result_gcd, diff);
            }
        }
    }

    cout << result_gcd << endl;
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