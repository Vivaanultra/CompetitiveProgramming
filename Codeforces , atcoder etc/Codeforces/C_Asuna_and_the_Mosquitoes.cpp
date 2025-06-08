#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// Using namespace and ll for competitive programming style
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum_val = 0;
    ll max_val = 0; 
    int odd_count = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum_val += a[i];
        if (a[i] > max_val) {
            max_val = a[i];
        }
        if (a[i] % 2 != 0) { // Odd
            odd_count++;
        }
    }
    
    if (odd_count == 0 || odd_count == n) {
        // Case 1: No operations possible (all elements same parity or n=1).
        cout << max_val << endl;
    } else {
        // Case 2: Operations are possible (0 < odd_count < n).
        // odd_count is an invariant.
        
        bool sum_and_odd_count_same_parity = ((sum_val % 2) == (odd_count % 2));

        if (sum_and_odd_count_same_parity) {
            // Max beauty is S - c_o + 1
            cout << sum_val - odd_count + 1 << endl;
        } else {
            // Max beauty is S - c_o
            cout << sum_val - odd_count << endl;
        }
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}