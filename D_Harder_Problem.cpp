#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(n);
    vector<int> freq(n + 1, 0);
    int cur_max = 0;
    int p = 1;

    for (int i = 0; i < n; ++i) {
        if (freq[a[i]] < cur_max) {
            b[i] = a[i];
            freq[a[i]]++;
        } else {
            if (cur_max == 0) {
                b[i] = a[i];
                freq[a[i]]++;
                cur_max = 1;
            } else {
                while (freq[p] != 0 || p == a[i]) {
                    p++;
                }
                b[i] = p;
                freq[p]++;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << b[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
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