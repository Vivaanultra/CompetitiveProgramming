#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        // 1. Find an anchor: first non-'?' character
        int anchor = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] != '?') {
                anchor = i;
                break;
            }
        }
        // 1a. If all are '?', pick s[0] = 'R' as a starting point
        if (anchor == -1) {
            s[0] = 'R';
            anchor = 0;
        }

        // 2. Sweep left from the anchor, alternating colors
        for (int i = anchor - 1; i >= 0; i--) {
            s[i] = (s[i+1] == 'R' ? 'B' : 'R');
        }

        // 3. Sweep right from the anchor, filling only '?' by alternating
        for (int i = anchor + 1; i < n; i++) {
            if (s[i] == '?') {
                s[i] = (s[i-1] == 'R' ? 'B' : 'R');
            }
        }

        // 4. Output the minimized-imperfectness string
        cout << s << "\n";
    }

    return 0;
}
