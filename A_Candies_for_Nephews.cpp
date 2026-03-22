#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    // Calculate remainder
    int rem = n % 3;
    
    // If remainder is 0, print 0. Otherwise print 3 - remainder.
    if (rem == 0) {
        cout << 0 << endl;
    } else {
        cout << 3 - rem << endl;
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