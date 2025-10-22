#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

/**
 * @brief Solves a single test case for the cake redistribution problem.
 */
void solve() {
    long long k, x;
    std::cin >> k >> x;

    // The initial number of cakes for Chocola is 2^k, which is our target in the backward process.
    long long target = 1LL << k;

    // If Chocola already has the target number of cakes, 0 steps are needed.
    if (x == target) {
        std::cout << 0 << std::endl;
        std::cout << std::endl;
        return;
    }

    // This vector will store the sequence of operations as we trace the path backward.
    std::vector<int> ops_backward;
    long long current_x = x;

    while (current_x != target) {
        if (current_x > target) {
            // If current cakes > 2^k, the previous state must be 2*(current_x - 2^k).
            // This corresponds to undoing a forward Operation 2 (Vanilla gives).
            ops_backward.push_back(2);
            current_x = 2 * (current_x - target);
        } else { // current_x < target
            // If current cakes < 2^k, the previous state must be 2*current_x.
            // This corresponds to undoing a forward Operation 1 (Chocola gives).
            ops_backward.push_back(1);
            current_x = 2 * current_x;
        }
    }

    // The actual sequence of operations is the reverse of what we recorded.
    std::cout << ops_backward.size() << std::endl;
    if (!ops_backward.empty()) {
        std::reverse(ops_backward.begin(), ops_backward.end());
        for (size_t i = 0; i < ops_backward.size(); ++i) {
            std::cout << ops_backward[i] << (i == ops_backward.size() - 1 ? "" : " ");
        }
    }
    std::cout << std::endl;
}

int main() {
    // Fast I/O for performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}