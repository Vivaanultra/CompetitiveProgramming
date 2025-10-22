#include <bits/stdc++.h>
using namespace std;

void solve() {
    string x;
    cin >> x;
    int first_digit = x[0] - '0';
    int len = x.length();
    int ans = (first_digit - 1) * 10;
    ans += (len * (len + 1)) / 2;
    cout << ans << endl;
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