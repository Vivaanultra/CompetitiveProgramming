#include <bits/stdc++.h>
using namespace std;

const int C_MAX = 1e7;
int div_sum[C_MAX + 1];
int ans[C_MAX + 1];

void precompute() {
    for (int i = 1; i <= C_MAX; ++i) {
        for (int j = i; j <= C_MAX; j += i) {
            div_sum[j] += i;
        }
    }
    
    fill(ans, ans + C_MAX + 1, -1);
    
    for (int n = 1; n <= C_MAX; ++n) {
        int c = div_sum[n];
        if (c <= C_MAX) {
            if (ans[c] == -1) {
                ans[c] = n;
            }
        }
    }
}

void solve() {
    int c;
    cin >> c;
    cout << ans[c] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}