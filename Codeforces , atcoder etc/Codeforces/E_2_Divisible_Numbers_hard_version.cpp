#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

// Per your preference for competitive programming
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Finds all divisors of a given number.
 * @param n The number to find divisors for.
 * @return A vector containing all divisors of n.
 */
vector<long long> get_divisors(long long n) {
    vector<long long> divisors;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            // Add the corresponding divisor if it's not the square root
            if (i * i != n) {
                divisors.push_back(n / i);
            }
        }
    }
    return divisors;
}

/**
 * @brief Solves a single test case.
 */
void solve() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    // Pre-calculate all divisors for a and b.
    vector<long long> divs_a = get_divisors(a);
    vector<long long> divs_b = get_divisors(b);

    long long ab_product = a * b;

    // Iterate through all pairs of divisors (d_a from a's divisors, d_b from b's)
    for (long long d_a : divs_a) {
        for (long long d_b : divs_b) {
            // g1 is a divisor of a*b formed by d_a * d_b
            long long g1 = d_a * d_b;
            // g2 is the complementary divisor such that g1 * g2 = a * b
            long long g2 = ab_product / g1;

            // Find the smallest multiple of g1 that is strictly greater than a.
            // This is our candidate for x.
            long long x = (a / g1 + 1) * g1;

            // Find the smallest multiple of g2 that is strictly greater than b.
            // This is our candidate for y.
            long long y = (b / g2 + 1) * g2;

            // Check if these candidates fall within the specified ranges.
            if (x <= c && y <= d) {
                cout << x << " " << y << endl;
                return;
            }
        }
    }

    // If the loops complete, no solution was found.
    cout << -1 << " " << -1 << endl;
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