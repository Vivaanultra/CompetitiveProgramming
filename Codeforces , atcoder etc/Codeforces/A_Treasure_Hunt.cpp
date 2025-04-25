#include <iostream>

long long calculate_depth(long long k, long long x, long long y) {
    if (k <= 0) {
        return 0;
    }

    long long num_b_turns;
    long long num_k_turns;

    if (k % 2 != 0) {
        num_b_turns = (k + 1) / 2;
        num_k_turns = (k - 1) / 2;
    } else {
        num_b_turns = k / 2;
        num_k_turns = k / 2;
    }

    long long depth_b = num_b_turns * x;
    long long depth_k = num_k_turns * y;

    if (depth_b > __LONG_LONG_MAX__ - depth_k) {
       return __LONG_LONG_MAX__;
    }

    return depth_b + depth_k;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;

    while (t--) {
        long long x, y, a;
        std::cin >> x >> y >> a;

        long long target_depth = a + 1;

        long long low = 1;
        long long high = 2000000000LL + 2;
        long long ans_k = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (mid <= 0) {
                low = 1;
                continue;
            }

            long long current_depth = calculate_depth(mid, x, y);

            if (current_depth >= target_depth) {
                ans_k = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (ans_k % 2 != 0) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
        }
    }

    return 0;
}