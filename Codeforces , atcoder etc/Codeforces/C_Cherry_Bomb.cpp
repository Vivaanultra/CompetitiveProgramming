#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n), b(n);
    long long min_a = -1, max_a = -1;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (min_a == -1 || a[i] < min_a) min_a = a[i];
        if (max_a == -1 || a[i] > max_a) max_a = a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    // 1. Determine the initial valid range for the sum 'x'
    long long min_x = max_a;
    long long max_x = min_a + k;

    // 2. Shrink the range based on known b[i] values
    for (int i = 0; i < n; ++i) {
        if (b[i] != -1) {
            long long required_sum = a[i] + b[i];
            min_x = max(min_x, required_sum);
            max_x = min(max_x, required_sum);
        }
    }

    // 3. Calculate the number of integers in the final range
    if (min_x > max_x) {
        cout << 0 << "\n";
    } else {
        cout << max_x - min_x + 1 << "\n";
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