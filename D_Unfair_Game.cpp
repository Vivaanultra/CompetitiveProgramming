#include <bits/stdc++.h>

using namespace std;

long long C[32][32];

void precompute() {
    for (int i = 0; i < 32; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    int d = 0;
    while ((1 << (d + 1)) <= n && (1 << (d + 1)) > 0) {
        d++;
    }
    if (n == 1) d = 0;
    else d = __builtin_ctz(n);

    long long ans = 0;
    for (int i = 0; i < d; i++) {
        int min_p = k - i;
        if (min_p > i) continue;
        int start_p = max(0, min_p);
        for (int p = start_p; p <= i; p++) {
            ans += C[i][p];
        }
    }
    if (d + 1 > k) {
        ans++;
    }
    cout << ans << "\n";
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