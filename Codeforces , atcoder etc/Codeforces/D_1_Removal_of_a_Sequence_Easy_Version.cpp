#include <iostream>

using namespace std;

void solve() {
    long long x, y, k;
    cin >> x >> y >> k;

    // Edge case: If y = 1, all numbers are removed immediately.
    // Since k >= 1, it's impossible to find the k-th number.
    if (y == 1) {
        cout << -1 << endl;
        return;
    }

    long long cur = k;
    long long limit = 1000000000000LL; // 10^12

    // Work backwards x times
    for (int i = 0; i < x; ++i) {
        // Formula to map index from 'after removal' to 'before removal'
        // We add the number of elements that were removed before this index.
        cur = cur + (cur - 1) / (y - 1);

        // If the index exceeds the initial sequence limit, 
        // then the k-th element doesn't exist in the valid range.
        if (cur > limit) {
            cout << -1 << endl;
            return;
        }
    }

    cout << cur << endl;
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