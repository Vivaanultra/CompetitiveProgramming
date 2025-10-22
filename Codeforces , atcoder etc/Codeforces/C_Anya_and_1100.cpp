#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int q;
    cin >> q;
    int n = s.length();

    set<int> occurrences;
    for (int i = 0; i <= n - 4; ++i) {
        if (s.substr(i, 4) == "1100") {
            occurrences.insert(i);
        }
    }

    while (q--) {
        int i, v;
        cin >> i >> v;
        int idx = i - 1;

        for (int j = max(0, idx - 3); j <= idx; ++j) {
            if (j + 3 < n) {
                if (s.substr(j, 4) == "1100") {
                    occurrences.erase(j);
                }
            }
        }

        s[idx] = (v == 1 ? '1' : '0');

        for (int j = max(0, idx - 3); j <= idx; ++j) {
            if (j + 3 < n) {
                if (s.substr(j, 4) == "1100") {
                    occurrences.insert(j);
                }
            }
        }

        if (occurrences.empty()) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
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