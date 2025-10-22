#include <iostream>
#include <algorithm>

// Function to solve a single test case
void solve() {
    long long a, b;
    std::cin >> a >> b;

    if (a >= b) {
        // If Alice has enough coins initially, she deposits everything.
        std::cout << a << std::endl;
    } else {
        // Otherwise, she needs to use the unprofitable deposit.
        // The maximum she can deposit is 2*a - b.
        // If this value is negative, it's impossible, so the answer is 0.
        long long result = 2 * a - b;
        std::cout << std::max(0LL, result) << std::endl;
    }
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

}