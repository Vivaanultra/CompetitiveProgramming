#include <iostream>
#include <cmath>

using namespace std;

void solve() {
    int n;
    cin >> n;

    // We can use the derived formula: 2^(n/2 + 1) - 2.
    // Using bitwise shift '<<' which is equivalent to power of 2.
    // 1 << x is equal to 2^x.
    
    int result = (1 << (n / 2 + 1)) - 2;
    
    cout << result << endl;
}

int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}