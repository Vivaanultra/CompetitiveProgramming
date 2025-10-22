#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool visited[26] = {false};
    for (int i = 0; i < n; ++i) {
        if (visited[s[i] - 'A']) {
            if (s[i] != s[i - 1]) {
                cout << "NO" << endl;
                return;
            }
        } else {
            visited[s[i] - 'A'] = true;
        }
    }
    cout << "YES" << endl;
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