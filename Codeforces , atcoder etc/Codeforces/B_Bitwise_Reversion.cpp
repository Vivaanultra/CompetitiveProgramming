#include <iostream>

using namespace std;

void solve() {
    long long x, y, z;
    cin >> x >> y >> z;

    
    if ((x & y) == (x & z) && (x & z) == (y & z)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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