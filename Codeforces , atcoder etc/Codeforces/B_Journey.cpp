#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, a, b, c;
    cin >> n >> a >> b >> c;

    long long cycle_dist = a + b + c;
    long long num_cycles = (n - 1) / cycle_dist;

    long long days_taken = num_cycles * 3;
    long long dist_covered = num_cycles * cycle_dist;
    long long dist_remaining = n - dist_covered;

    if (dist_remaining > 0) {
        days_taken++;
        dist_remaining -= a;
    }
    if (dist_remaining > 0) {
        days_taken++;
        dist_remaining -= b;
    }
    if (dist_remaining > 0) {
        days_taken++;
        dist_remaining -= c;
    }

    cout << days_taken << "\n";
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