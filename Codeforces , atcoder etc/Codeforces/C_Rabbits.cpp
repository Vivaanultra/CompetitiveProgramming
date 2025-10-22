#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; string s;
        cin >> n >> s;
        bool ok = true;
        for (int i = 0; i < n && ok; ++i) {
            if (s[i] == '1') {
                int j = i;
                // extend while pattern 1 0 1 0 1 ... holds
                while (j + 2 < n && s[j+1] == '0' && s[j+2] == '1') j += 2;
                int len = j - i + 1; // odd length >=1
                if (len >= 3 && (len % 4) == 3) {
                    bool left_block = (i == 0) || (s[i-1] == '1');
                    bool right_block = (j == n-1) || (s[j+1] == '1');
                    if (left_block && right_block) {
                        ok = false;
                        break;
                    }
                }
                i = j; // continue after this run
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
