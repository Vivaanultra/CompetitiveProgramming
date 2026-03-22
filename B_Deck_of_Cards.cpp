#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;
    string s;
    cin >> s;

    int c0 = 0, c1 = 0, c2 = 0;
    for (char c : s) {
        if (c == '0') c0++;
        else if (c == '1') c1++;
        else c2++;
    }

    string res = "";
    res.reserve(n);

    for (int i = 1; i <= n; ++i) {
        int l_bound = c1 + c2 - n + i;
        int r_bound = i - c0 - 1;

        int valid_l = max(0, l_bound);
        int valid_r = min(c2, r_bound);

        if (valid_l > valid_r) {
            res += '-';
        } else {
            if (l_bound <= 0 && r_bound >= c2) {
                res += '+';
            } else {
                res += '?';
            }
        }
    }
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}