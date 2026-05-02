#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    for (char c : s) {
        cnt[c - 'a']++;
    }
    int mx = 0;
    for (int x : cnt) {
        mx = max(mx, x);
    }
    if (mx > n / 2) {
        cout << 2 * mx - n << "\n";
    } else {
        cout << n % 2 << "\n";
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