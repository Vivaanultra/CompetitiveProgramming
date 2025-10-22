#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    char min_digit = '9';
    for (char c : s) {
        min_digit = min(min_digit, c);
    }
    cout << min_digit << endl;
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