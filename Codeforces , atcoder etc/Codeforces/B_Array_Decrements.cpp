#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// Using competitive programming practices
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    // Find the required number of operations, k.
    // It must be at least the largest difference between any a[i] and b[i].
    long long k = 0;
    for (int i = 0; i < n; ++i) {
        // If any a[i] is smaller than b[i], it's impossible.
        if (a[i] < b[i]) {
            cout << "NO" << endl;
            return;
        }
        if (a[i] - b[i] > k) {
            k = a[i] - b[i];
        }
    }

    // Now, verify if applying k operations works for all elements.
    for (int i = 0; i < n; ++i) {
        // The value of a[i] after k operations becomes max(0, a[i] - k).
        // This must match b[i].
        if (b[i] != max(0LL, a[i] - k)) {
            cout << "NO" << endl;
            return;
        }
    }

    // If all checks pass, it's possible.
    cout << "YES" << endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}