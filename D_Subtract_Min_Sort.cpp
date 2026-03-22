#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // We process the array from left to right.
    // 'prev' tracks the value of a[i-1] after it has been finalized.
    int prev = 0; 

    for (int i = 0; i < n - 1; ++i) {
        // Option 1: Perform the operation
        // Subtract min(a[i], a[i+1]) from both.
        int m = min(a[i], a[i+1]);
        int op_ai = a[i] - m;
        int op_next = a[i+1] - m;

        // Greedy Decision:
        // Always prefer the operation if it maintains the sorted order with 'prev'.
        // Lower values are strictly better for future steps.
        if (op_ai >= prev) {
            a[i] = op_ai;
            a[i+1] = op_next;
        } else {
            // If operation makes a[i] too small, we are forced to keep the current values.
            // Check if the current value is even valid.
            if (a[i] < prev) {
                cout << "NO" << "\n";
                return;
            }
            // If valid, do nothing and proceed.
        }
        
        // Update prev for the next iteration
        prev = a[i];
    }

    // Final check: Is the last pair sorted?
    if (a[n-1] < a[n-2]) {
        cout << "NO" << "\n";
    } else {
        cout << "YES" << "\n";
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