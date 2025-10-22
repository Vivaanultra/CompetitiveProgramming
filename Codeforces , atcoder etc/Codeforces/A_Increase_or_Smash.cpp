#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        unordered_set<int> s;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            s.insert(x);
        }
        int m = (int)s.size();
        cout << (2 * m - 1) << '\n';
    }
    return 0;
}
