#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    
    // Alice wins if the initial distance is even.
    if (abs(a - b) % 2 == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}