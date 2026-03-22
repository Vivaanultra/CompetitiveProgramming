#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int l, a, b;
    cin >> l >> a >> b;
    
    int current = a;
    int max_val = a;
    
    // The cycle repeats at most every l steps.
    // Iterating l times covers all reachable positions.
    for (int i = 0; i < l; ++i) {
        current = (current + b) % l;
        max_val = max(max_val, current);
    }
    
    cout << max_val << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}