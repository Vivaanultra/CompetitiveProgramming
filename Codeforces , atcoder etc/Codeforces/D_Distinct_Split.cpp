#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    vector<int> suf(n);
    vector<bool> vis(26, false);
    int cnt = 0;
    
    for (int i = n - 1; i >= 0; i--) {
        if (!vis[s[i] - 'a']) {
            vis[s[i] - 'a'] = true;
            cnt++;
        }
        suf[i] = cnt;
    }
    
    fill(vis.begin(), vis.end(), false);
    cnt = 0;
    int ans = 0;
    
    for (int i = 0; i < n - 1; i++) {
        if (!vis[s[i] - 'a']) {
            vis[s[i] - 'a'] = true;
            cnt++;
        }
        ans = max(ans, cnt + suf[i + 1]);
    }
    
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}