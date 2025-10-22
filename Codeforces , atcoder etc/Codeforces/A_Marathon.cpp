#include <iostream>

// Include for competitive programming convenience
#include <bits/stdc++.h>
using namespace std;

// Function to solve a single test case
void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d; // Read Timur's distance and the others'

    int ahead_count = 0;
    // Check if runner 'b' is ahead of Timur
    if (b > a) {
        ahead_count++;
    }
    // Check if runner 'c' is ahead of Timur
    if (c > a) {
        ahead_count++;
    }
    // Check if runner 'd' is ahead of Timur
    if (d > a) {
        ahead_count++;
    }

    cout << ahead_count << endl; // Output the total count
}

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve();
    }

    return 0;
}