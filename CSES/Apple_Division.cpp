#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> p(n);
    long long total_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        total_sum += p[i];
    }

    long long min_diff = total_sum;

    for (int mask = 0; mask < (1 << n); mask++) {
        long long current_sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                current_sum += p[i];
            }
        }
        
        long long current_diff = abs(total_sum - 2 * current_sum);
        min_diff = min(min_diff, current_diff);
    }

    cout << min_diff << "\n";

    return 0;
}