#include <iostream>
#include <numeric> // Required for std::gcd in C++17

// This function calculates the greatest common divisor (GCD) of two numbers.
// Note: std::gcd is available in C++17. If you are using an older standard,
// you might need to implement your own GCD function.
long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

void solve() {
    long long a, b;
    std::cin >> a >> b;

    // The smallest number m satisfying the conditions is the
    // Least Common Multiple (LCM) of a and b.
    // We calculate lcm(a, b) using the formula: (a * b) / gcd(a, b)
    // To prevent potential overflow, it's calculated as (a / gcd(a, b)) * b
    long long common_divisor = gcd(a, b);
    long long lcm = (a / common_divisor) * b;

    std::cout << lcm << std::endl;
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

    return 0;
}