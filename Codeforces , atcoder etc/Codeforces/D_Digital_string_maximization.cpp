#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int best = s[i] - '0';
            int pos = i;
            // Only need to look up to 9 positions ahead
            for (int j = i; j < n && j <= i + 9; ++j) {
                int cur = (s[j] - '0') - (j - i);
                if (cur > best) {
                    best = cur;
                    pos = j;
                }
            }
            // Move chosen element to position i (by swapping)
            while (pos > i) {
                swap(s[pos], s[pos - 1]);
                --pos;
            }
            // The moved digit after (j-i) decrements becomes 'best'
            s[i] = char('0' + best);
        }
        cout << s << '\n';
    }
    return 0;
}
