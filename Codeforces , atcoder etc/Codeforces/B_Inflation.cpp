#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    long long total_increase = 0;
    long long current_sum = p[0];

    for (int i = 1; i < n; ++i) {
        if (100LL * p[i] > k * current_sum) {
            long long required_sum = (100LL * p[i] + k - 1) / k;
            long long delta = required_sum - current_sum;
            total_increase += delta;
            current_sum += delta;
        }
        current_sum += p[i];
    }
    cout << total_increase << endl;
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