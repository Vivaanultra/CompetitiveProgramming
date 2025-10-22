#include <bits/stdc++.h>
using namespace std;

// Helper to get the i-th bit of n
bool get_bit(int n, int i) {
    if (i < 0) return 0;
    return (n >> i) & 1;
}

// Checks if an even x with k bits and j trailing zeros can form n
bool check(int n, int k, int j) {
    if (j <= 0 || j >= k) return false;

    vector<int> b(k, -1); // Bits of x, -1 means unknown

    // Phase 1: Initial definitions from n
    // Define top bits of x from n
    for (int i = k - j; i < k; ++i) {
        b[i] = get_bit(n, i);
    }
    // Define middle bits of x from bottom bits of n
    for (int i = j; i < 2 * j; ++i) {
        if (i >= k) continue;
        b[i] = get_bit(n, i - j);
    }

    // Phase 2: Check for contradictions in overlapping definitions
    for (int i = k - j; i < 2 * j; ++i) {
        if (i >= k) continue;
        if (get_bit(n, i) != get_bit(n, i - j)) {
            return false;
        }
    }
    
    // Phase 3: Propagate constraints to fill gaps
    for (int i = 2 * j; i < k; ++i) {
        if (b[i] == -1) {
             if (b[i - j] == -1) return false; // Should not happen with this loop order
             b[i] = get_bit(n, i - j) ^ b[i - j];
        } else { // Already defined, check for contradiction
             if (b[i] != (get_bit(n, i-j) ^ b[i-j])) {
                 return false;
             }
        }
    }
    
    // Phase 4: Final verification of x's structure
    if (b[k - 1] != 1) return false; // MSB must be 1
    if (b[j] != 1) return false;     // Lowest set bit must be at j

    return true;
}

bool is_binary_palindrome(int num) {
    if (num == 0) return true;
    int len = 31 - __builtin_clz(num);
    int left = len, right = 0;
    while (right < left) {
        if (get_bit(num, left) != get_bit(num, right)) {
            return false;
        }
        left--; right++;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << "YES\n";
        return;
    }

    if (n % 2 == 0) {
        if (is_binary_palindrome(n / 2)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else { // n is odd, x must be even
        bool found = false;
        int k = 31 - __builtin_clz(n);
        for (int j = 1; j <= k; ++j) {
            if (check(n, k + 1, j)) {
                found = true;
                break;
            }
        }
        if (found) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
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