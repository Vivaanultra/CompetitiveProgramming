#include <bits/stdc++.h>
using namespace std;

// Helper function to calculate the integer square root of a 128-bit integer.
// It uses binary search to find the result efficiently.
__int128 isqrt(__int128 n) {
    if (n < 0) return 0;
    __int128 low = 1, high = 2e12, ans = 0; // A safe upper bound for sqrt of the discriminant
    while (low <= high) {
        __int128 mid = low + (high - low) / 2;
        // Using division to avoid overflow from mid*mid
        if (mid > n / mid) {
            high = mid - 1;
        } else {
            ans = mid;
            low = mid + 1;
        }
    }
    return ans;
}

void solve() {
    int n;
    long long c;
    cin >> n >> c;

    // Step 1: Pre-calculate sums. This is O(N).
    long long sum_s = 0;
    long long sum_s_sq = 0;
    for (int i = 0; i < n; i++) {
        long long s;
        cin >> s;
        sum_s += s;
        sum_s_sq += s * s;
    }

    // Step 2: Solve the quadratic equation using the formula.
    // Cast to __int128 to handle large numbers.
    __int128 n_128 = n;
    __int128 c_128 = c;
    __int128 sum_s_128 = sum_s;
    __int128 sum_s_sq_128 = sum_s_sq;

    // Calculate the term inside the square root (part of the discriminant)
    __int128 discriminant_inner = sum_s_128 * sum_s_128 - n_128 * (sum_s_sq_128 - c_128);

    // Calculate the integer square root of the discriminant part
    __int128 root_val = isqrt(discriminant_inner);

    // Calculate the numerator and denominator of the final formula for w
    __int128 numerator = -sum_s_128 + root_val;
    __int128 denominator = 2 * n_128;

    // The result is the final answer for w
    long long w = numerator / denominator;
    cout << w << "\n";
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