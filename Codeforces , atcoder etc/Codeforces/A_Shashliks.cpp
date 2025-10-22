#include <iostream>
#include <algorithm>

// Function to solve a single test case
void solve() {
    long long k, a, b, x, y;
    std::cin >> k >> a >> b >> x >> y;

    long long max_shashliks = 0;

    // Strategy 1: Cook only shashliks of the first type.
    if (k >= a) {
        long long count1_only = (k - a) / x + 1;
        max_shashliks = std::max(max_shashliks, count1_only);
    }

    // Strategy 2: Cook only shashliks of the second type.
    if (k >= b) {
        long long count2_only = (k - b) / y + 1;
        max_shashliks = std::max(max_shashliks, count2_only);
    }

    // Strategy 3: Cook the maximum possible number of the first type,
    // then cook the maximum possible number of the second type.
    if (k >= a) {
        long long count1_max = (k - a) / x + 1;
        long long temp_after_1 = k - count1_max * x;
        long long total_count = count1_max;
        if (temp_after_1 >= b) {
            total_count += (temp_after_1 - b) / y + 1;
        }
        max_shashliks = std::max(max_shashliks, total_count);
    }

    // Strategy 4: Cook the maximum possible number of the second type,
    // then cook the maximum possible number of the first type.
    if (k >= b) {
        long long count2_max = (k - b) / y + 1;
        long long temp_after_2 = k - count2_max * y;
        long long total_count = count2_max;
        if (temp_after_2 >= a) {
            total_count += (temp_after_2 - a) / x + 1;
        }
        max_shashliks = std::max(max_shashliks, total_count);
    }

    std::cout << max_shashliks << std::endl;
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