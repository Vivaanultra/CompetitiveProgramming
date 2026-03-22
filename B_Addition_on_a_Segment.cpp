#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    vector<int> c(n + 1);
    int running_count = 0;
    for (int i = n; i >= 1; --i) {
        running_count += cnt[i];
        c[i] = running_count;
    }

    long long p_sum = 0;
    long long ans = -1;

    for (int k = 1; k <= n; ++k) {
        p_sum += c[k];
        long long val = p_sum - k + 1;
        if (ans == -1 || val < ans) {
            ans = val;
        }
    }

    cout << ans << "\n";
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