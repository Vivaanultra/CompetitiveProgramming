#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    deque<int> p;
    p.push_back(n);

    bool to_left = true;
    for (int i = n - 1; i >= 1; --i) {
        if (to_left) {
            p.push_front(i);
        } else {
            p.push_back(i);
        }
        to_left = !to_left;
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