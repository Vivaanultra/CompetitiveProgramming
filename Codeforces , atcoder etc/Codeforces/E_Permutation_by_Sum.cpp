#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, l, r, s;
    cin >> n >> l >> r >> s;

    long long k = r - l + 1;
    long long min_sum = k * (k + 1) / 2;
    long long max_sum = k * (2 * n - k + 1) / 2;

    if (s < min_sum || s > max_sum) {
        cout << -1 << endl;
        return;
    }

    vector<long long> sub(k);
    for (int i = 0; i < k; ++i) {
        sub[i] = i + 1;
    }

    long long remaining_s = s - min_sum;
    for (int i = k - 1; i >= 0; --i) {
        long long max_val = n - (k - 1 - i);
        long long add = min(remaining_s, max_val - sub[i]);
        sub[i] += add;
        remaining_s -= add;
    }

    vector<long long> p(n);
    vector<bool> used(n + 1, false);
    for (int i = 0; i < k; ++i) {
        p[l - 1 + i] = sub[i];
        used[sub[i]] = true;
    }

    int current_val = 1;
    for (int i = 0; i < n; ++i) {
        if (p[i] == 0) {
            while (used[current_val]) {
                current_val++;
            }
            p[i] = current_val;
            used[current_val] = true;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << p[i] << " ";
    }
    cout << endl;
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