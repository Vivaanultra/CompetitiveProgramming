#include <bits/stdc++.h>

using namespace std;

long long F(int n) {
    long long total_changes = 0;
    while (n > 0) {
        total_changes += n;
        n /= 10;
    }
    return total_changes;
}

void solve() {
    int l, r;
    cin >> l >> r;
    cout << F(r) - F(l) << endl;
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