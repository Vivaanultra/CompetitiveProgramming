#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    unordered_set<string> st;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        st.insert(s[i]);
    }

    string ans = "";
    for (int i = 0; i < n; ++i) {
        bool found = false;
        for (int j = 1; j < s[i].length(); ++j) {
            string prefix = s[i].substr(0, j);
            string suffix = s[i].substr(j);
            if (st.count(prefix) && st.count(suffix)) {
                found = true;
                break;
            }
        }
        if (found) {
            ans += '1';
        } else {
            ans += '0';
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