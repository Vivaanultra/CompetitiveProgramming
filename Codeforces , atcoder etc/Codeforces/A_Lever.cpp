#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    long long total_excess = 0;

    // Calculate the total number of "decrease" operations that must be performed.
    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) {
            total_excess += a[i] - b[i];
        }
    }
    
    // It takes `total_excess` iterations to perform all the decreases.
    // After that, one final iteration is performed where the stop condition is met.
    cout << total_excess + 1 << endl;
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