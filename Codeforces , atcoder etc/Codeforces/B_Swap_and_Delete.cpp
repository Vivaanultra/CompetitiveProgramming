#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();

    int total_zeros = 0;
    for (char c : s) {
        if (c == '0') {
            total_zeros++;
        }
    }
    int total_ones = n - total_zeros;

    int prefix_zeros = total_zeros;
    int prefix_ones = total_ones;

    // Linearly scan k from n down to 0
    for (int k = n; k >= 0; --k) {
        // Check if a good string of length k is possible
        // Zeros needed for t = prefix_ones
        // Ones needed for t = prefix_zeros
        if (prefix_ones <= total_zeros && prefix_zeros <= total_ones) {
            // Found the largest possible k, so the cost is n - k
            cout << n - k << "\n";
            return;
        }

        // Prepare for next iteration (length k-1)
        // by removing the last character of the current prefix
        if (k > 0) {
            if (s[k - 1] == '0') {
                prefix_zeros--;
            } else {
                prefix_ones--;
            }
        }
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