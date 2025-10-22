#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int upvotes = 0;
    for (int i = 0; i < n; ++i) {
        int r;
        cin >> r;
        if (r == 1 || r == 3) {
            upvotes++;
        }
    }
    cout << upvotes << endl;
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