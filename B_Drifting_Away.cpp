#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    
    for (int i = 0; i < n - 1; i++) {
        if (s[i] != '<' && s[i+1] != '>') {
            cout << -1 << "\n";
            return;
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '<' || s[i] == '*') {
            ans = max(ans, i + 1);
        }
        if (s[i] == '>' || s[i] == '*') {
            ans = max(ans, n - i);
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