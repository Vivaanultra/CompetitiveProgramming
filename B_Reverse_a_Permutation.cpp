#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> pos(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        pos[p[i]] = i;
    }

    int target = n;
    int l = -1, r = -1;

    for (int i = 0; i < n; ++i) {
        if (p[i] == target) {
            target--;
        } else {
            l = i;
            r = pos[target];
            break;
        }
    }

    if (l != -1) {
        reverse(p.begin() + l, p.begin() + r + 1);
    }

    for (int i = 0; i < n; ++i) {
        cout << p[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
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