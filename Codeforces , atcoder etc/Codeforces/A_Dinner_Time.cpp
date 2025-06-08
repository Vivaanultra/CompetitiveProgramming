#include <iostream>

void solve() {
    long long n, m, p, q_val; // Using q_val to avoid potential keyword clash, though 'q' is fine as a local variable.
    std::cin >> n >> m >> p >> q_val;

    long long k = n / p; // Number of full blocks of p elements
    long long r = n % p; // Number of remaining elements

    if (r == 0) {
        // n is a multiple of p.
        // The total sum must be k * q_val.
        if (m == k * q_val) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    } else {
        // n is not a multiple of p (so r > 0).
        // As explained in the logic, an array can always be constructed in this case
        // because elements can be negative integers.
        std::cout << "YES" << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}