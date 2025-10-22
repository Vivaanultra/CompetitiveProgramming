#include <iostream>
#include <cmath>

// Using std namespace for convenience in competitive programming
using namespace std;

// Function to solve a single test case
void solve() {
    long long n, k, p;
    cin >> n >> k >> p;

    // If the target sum is 0, the initial array of zeros already satisfies the condition.
    // No operations are needed.
    if (k == 0) {
        cout << 0 << "\n";
        return;
    }

    // Let 'm' be the number of operations.
    // In each operation, we change a 0 to a number 'x' where -p <= x <= p.
    // To achieve a sum of 'k' with 'm' operations, the sum must be within the
    // minimum and maximum possible sums achievable with 'm' operations.
    // Minimum sum: m * (-p)
    // Maximum sum: m * p
    // So, we must have: m * (-p) <= k <= m * p
    // This simplifies to: abs(k) <= m * p

    // We want to find the minimum 'm' that satisfies this.
    // Since m and p are positive, we can rearrange: m >= abs(k) / p.
    // Since 'm' must be an integer, the smallest 'm' is ceil(abs(k) / p).
    long long abs_k = abs(k);
    long long min_ops_for_sum = (abs_k + p - 1) / p; // Integer division trick for ceiling

    // The number of operations 'm' cannot be greater than the size of the array 'n'.
    if (min_ops_for_sum > n) {
        // If the minimum operations required to achieve the sum's magnitude
        // is more than the number of available slots, it's impossible.
        cout << -1 << "\n";
    } else {
        // The crucial insight is that the set of all possible sums using 'm' operations
        // is the continuous range of integers [-m*p, m*p]. There are no hidden
        // parity or other constraints.
        // Therefore, if the number of operations is sufficient for the sum's magnitude
        // and does not exceed the array size, it is the answer.
        cout << min_ops_for_sum << "\n";
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
