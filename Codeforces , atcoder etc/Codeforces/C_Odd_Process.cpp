#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> odds, evens;
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        if (x % 2 != 0) odds.push_back(x);
        else evens.push_back(x);
    }

    sort(odds.rbegin(), odds.rend());
    sort(evens.rbegin(), evens.rend());

    int n_odds = odds.size();
    int n_evens = evens.size();

    vector<long long> pref_evens(n_evens + 1, 0);
    for (int i = 0; i < n_evens; ++i) {
        pref_evens[i + 1] = pref_evens[i] + evens[i];
    }

    for (int k = 1; k <= n; ++k) {
        int count_e = min(k, n_evens);
        int count_o = k - count_e;

        if (count_o % 2 == 0) {
            count_o++;
            count_e--;
        }

        if (count_o > n_odds || count_e < 0) {
            cout << 0 << " ";
        } else {
            cout << odds[0] + pref_evens[count_e] << " ";
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}