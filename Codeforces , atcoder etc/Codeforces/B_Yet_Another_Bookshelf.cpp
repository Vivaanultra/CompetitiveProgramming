#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int first = -1, last = -1;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1) {
            if (first == -1) {
                first = i;
            }
            last = i;
        }
    }

    if (first == -1 || first == last) {
        cout << 0 << endl;
        return;
    }

    int gaps = 0;
    for (int i = first; i <= last; ++i) {
        if (a[i] == 0) {
            gaps++;
        }
    }
    cout << gaps << endl;
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