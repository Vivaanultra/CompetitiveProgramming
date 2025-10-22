#include <bits/stdc++.h>
using namespace std;

// This function solves a single test case.
void solve() {
    int n;
    int x;
    cin >> n >> x;
    
    int sum = 0;
    // Read the array elements and calculate their sum.
    // We don't need to store the array itself.
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        sum += val;
    }
    
    // The main insight is that the average of the elements in the array
    // is an invariant. It does not change after any operation.
    // The process ends when the array has a single element, say [y].
    // The average of this final array is y.
    // Therefore, the final element must be equal to the average of the initial array.
    // Initial Average = sum / n.
    // We require the final element to be x.
    // So, we must have sum / n == x, which means sum == n * x.
    
    if (sum == (long long)n * x) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}