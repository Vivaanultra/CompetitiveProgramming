#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;

    // The key insight is that an odd subtraction flips the parity of n,
    // while an even subtraction preserves it. Once n becomes even, it will
    // always remain even. To minimize operations, we should always subtract
    // the largest number possible under the given parity constraints.

    if (n % 2 != k % 2) {
        // n is even, k is odd.
        // We must subtract an even number x (1 <= x <= k).
        // n will always remain even. To finish in minimum steps, we
        // always subtract the largest possible even number, which is k - 1.
        // The number of operations is ceil(n / (k - 1)).
        long long denominator = k - 1;
        cout << (n + denominator - 1) / denominator << endl;
    } else {
        // n is odd, k is odd.
        // We must subtract an odd number x. To make the remaining number
        // as small as possible, we subtract the largest odd number, k.
        // This costs 1 operation and leaves us with an even number, n - k.
        // The rest of the problem is solving for the even number n - k.
        long long remaining_n = n - k;
        long long ops = 1;
        if (remaining_n > 0) {
            long long denominator = k - 1;
            ops += (remaining_n + denominator - 1) / denominator;
        }
        cout << ops << endl;
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