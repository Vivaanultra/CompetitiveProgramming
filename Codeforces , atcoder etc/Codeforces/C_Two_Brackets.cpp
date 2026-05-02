#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int ans = 0;
    int open_round = 0;
    int open_square = 0;

    for (char c : s) {
        if (c == '(') {
            open_round++;
        } else if (c == '[') {
            open_square++;
        } else if (c == ')') {
            if (open_round > 0) {
                ans++;
                open_round--;
            }
        } else if (c == ']') {
            if (open_square > 0) {
                ans++;
                open_square--;
            }
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