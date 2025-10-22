#include <bits/stdc++.h>

using namespace std;

const long long INF = 4e18;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long initial_sum = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if ((i + 1) % 2 != 0) {
            initial_sum += a[i];
        } else {
            initial_sum -= a[i];
        }
    }

    long long max_gain = 0;

    long long min_odd_term = INF;
    long long max_even_term = -INF;
    for (int i = 0; i < n; ++i) {
        long long r = i + 1;
        if (r % 2 == 0) {
            if (min_odd_term != INF) {
                max_gain = max(max_gain, (2 * a[i] + r) - min_odd_term);
            }
            max_even_term = max(max_even_term, 2 * a[i] - r);
        } else {
            if (max_even_term != -INF) {
                max_gain = max(max_gain, max_even_term - (2 * a[i] - r));
            }
            min_odd_term = min(min_odd_term, 2 * a[i] + r);
        }
    }
    
    long long first_odd = -1, last_odd = -1;
    long long first_even = -1, last_even = -1;
    for (int i = 0; i < n; ++i) {
        long long r = i + 1;
        if (r % 2 != 0) {
            if (first_odd == -1) first_odd = r;
            last_odd = r;
        } else {
            if (first_even == -1) first_even = r;
            last_even = r;
        }
    }

    if (first_odd != -1 && last_odd != first_odd) {
        max_gain = max(max_gain, last_odd - first_odd);
    }
    if (first_even != -1 && last_even != first_even) {
        max_gain = max(max_gain, last_even - first_even);
    }

    cout << initial_sum + max_gain << endl;
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