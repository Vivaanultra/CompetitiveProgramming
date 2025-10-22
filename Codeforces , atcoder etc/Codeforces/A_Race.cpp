#include <iostream>
#include <cmath>
#include <algorithm>

// Function to solve a single test case
void solve() {
    long long a, x, y;
    std::cin >> a >> x >> y;

    // Calculate Alice's distances to the prize locations
    long long dist_ax = std::abs(a - x);
    long long dist_ay = std::abs(a - y);

    // Determine the required interval for Bob for prize at x: (lx, rx)
    long long lx = x - dist_ax;
    long long rx = x + dist_ax;

    // Determine the required interval for Bob for prize at y: (ly, ry)
    long long ly = y - dist_ay;
    long long ry = y + dist_ay;

    // Find the intersection of the two intervals
    long long intersect_lower = std::max(lx, ly);
    long long intersect_upper = std::min(rx, ry);

    // Check if there is at least one integer in the open interval (intersect_lower, intersect_upper).
    // This is true if the length of the interval is greater than 1.
    if (intersect_upper > intersect_lower + 1) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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

    return 0;
}