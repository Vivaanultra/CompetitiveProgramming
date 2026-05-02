#include<bits/stdc++.h>
using namespace std;

long long a[502][502], s[502][502], mx;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, q;
    cin >> n >> k >> q;

    while (q--) {
        int r, c;
        long long v;
        cin >> r >> c >> v;

        long long d = v - a[r][c];
        a[r][c] = v;

        for (int i = max(1, r - k + 1); i <= min(n - k + 1, r); ++i) {
            for (int j = max(1, c - k + 1); j <= min(n - k + 1, c); ++j) {
                s[i][j] += d;
                mx = max(mx, s[i][j]);
            }
        }
        cout << mx << "\n";
    }
    return 0;
}