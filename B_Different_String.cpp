#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    string r = s;
    sort(r.begin(), r.end());
    if (r == s) {
        reverse(r.begin(), r.end());
    }
    if (r == s) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl << r << endl;
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