#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    // As derived: 1.5x = 3n  =>  x = 2n
    cout << 2 * n << "\n";
}

int main() {
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}