#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    if (count(s.begin(), s.end(), s[0]) == n) { cout << "NO\n"; return; }

    for (int p = 0; p * 2 < n - 1; p++) {
        map<pair<char, char>, int> m;
        int diffs = 0;
        for (int i = 0; i < p; i++) {
            if (s[i] != s[n - 1 - i]) {
                m[{min(s[i], s[n - 1 - i]), max(s[i], s[n - 1 - i])}]++;
                diffs++;
            }
        }
        int save = 0;
        vector<pair<char, char>> spares;
        for (auto x : m) {
            save += x.second / 2;
            if (x.second % 2) spares.push_back(x.first);
        }

        int cost = diffs - save;
        char u = s[p], v = s[n - 1 - p];
        
        if (u >= v) {
            cost++; // Base cost to fix pivot
            for (auto x : spares) {
                char a = x.first, b = x.second;
                // Check if we can fix the pivot AND a spare mismatch in 1 swap
                if ((a < v && b == u) || (b < v && a == u) || 
                    (u < a && b == v) || (u < b && a == v)) {
                    cost--; break;
                }
            }
        }
        if (cost <= k) { cout << "YES\n"; return; }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}