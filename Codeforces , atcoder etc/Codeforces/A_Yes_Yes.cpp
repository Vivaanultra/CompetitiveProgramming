#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    string pattern = "";
    for (int i = 0; i < 18; ++i) {
        pattern += "Yes";
    }

    if (pattern.find(s) != string::npos) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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