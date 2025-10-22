#include <bits/stdc++.h>

using namespace std;

void solve() {
    int m;
    long long s;
    cin >> m >> s;
    
    int max_val = 0;
    long long current_sum = 0;
    for (int i = 0; i < m; ++i) {
        int b;
        cin >> b;
        current_sum += b;
        max_val = max(max_val, b);
    }

    long long total_target_sum = current_sum + s;
    long long n = max_val;

    while (true) {
        long long permutation_sum = n * (n + 1) / 2;
        if (permutation_sum >= total_target_sum) {
            if (permutation_sum == total_target_sum) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
            return;
        }
        n++;
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