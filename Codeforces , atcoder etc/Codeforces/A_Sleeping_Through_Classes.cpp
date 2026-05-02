#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<bool> awake(n, false);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                for (int j = i; j <= min(n - 1, i + k); ++j) {
                    awake[j] = true;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!awake[i]) {
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}