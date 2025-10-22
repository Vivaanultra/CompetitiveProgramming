#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> b(n / 2);
    vector<bool> is_in_b(n + 1, false);
    bool possible = true;

    for (int i = 0; i < n / 2; ++i) {
        cin >> b[i];
        if (is_in_b[b[i]]) {
            possible = false;
        }
        is_in_b[b[i]] = true;
    }

    if (!possible) {
        cout << -1 << endl;
        return;
    }

    set<int> available;
    for (int i = 1; i <= n; ++i) {
        if (!is_in_b[i]) {
            available.insert(i);
        }
    }

    vector<int> p(n);
    for (int i = n / 2 - 1; i >= 0; --i) {
        p[2 * i + 1] = b[i];
        auto it = available.lower_bound(b[i]);

        if (it == available.begin()) {
            possible = false;
            break;
        }
        
        it--;
        p[2 * i] = *it;
        available.erase(it);
    }

    if (!possible) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < n; ++i) {
            cout << p[i] << " ";
        }
        cout << endl;
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