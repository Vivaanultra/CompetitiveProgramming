#include <bits/stdc++.h>
using namespace std;

int get_luck(int n) {
    int mx = 0, mn = 9;
    while (n > 0) {
        int d = n % 10;
        mx = max(mx, d);
        mn = min(mn, d);
        n /= 10;
    }
    return mx - mn;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        int ans = l;
        int max_l = -1;
        for (int i = l; i <= r; ++i) {
            int cur_l = get_luck(i);
            if (cur_l > max_l) {
                max_l = cur_l;
                ans = i;
            }
            if (max_l == 9) break;
        }
        cout << ans << "\n";
    }
    return 0;
}