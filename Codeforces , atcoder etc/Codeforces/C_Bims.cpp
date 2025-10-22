#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int nim_sum = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a % 2 != 0) {
            nim_sum ^= 1;
        } else {
            nim_sum ^= 2;
        }
    }
    if (nim_sum != 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
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