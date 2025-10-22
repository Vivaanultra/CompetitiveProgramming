#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    set<int> existing_nums;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x != -1) {
            existing_nums.insert(x);
        }
    }

    if (existing_nums.empty()) {
        cout << "YES\n";
    } else if (existing_nums.count(0)) {
        cout << "NO\n";
    } else if (existing_nums.size() > 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
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