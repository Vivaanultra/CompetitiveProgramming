#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    int r = 0, c = 0; // Current relative position
    int max_r = 0, min_r = 0;
    int max_c = 0, min_c = 0;

    int ans_r = 1, ans_c = 1;

    for (char cmd : s) {
        if (cmd == 'U') r--;
        if (cmd == 'D') r++;
        if (cmd == 'L') c--;
        if (cmd == 'R') c++;

        max_r = max(max_r, r);
        min_r = min(min_r, r);
        max_c = max(max_c, c);
        min_c = min(min_c, c);

        // Check if the current path's bounding box fits
        if (max_r - min_r + 1 > n || max_c - min_c + 1 > m) {
            // If it doesn't fit, the previous state's answer is the best we can do.
            break; 
        }

        // If it fits, this is a new valid (and longer) path.
        // Calculate the top-left start position that makes this path valid.
        ans_r = 1 - min_r;
        ans_c = 1 - min_c;
    }

    cout << ans_r << " " << ans_c << endl;
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