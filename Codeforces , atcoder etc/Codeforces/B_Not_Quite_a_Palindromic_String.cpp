#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;

    int count0 = 0;
    int count1 = 0;
    for (char c : s) {
        if (c == '0') {
            count0++;
        } else {
            count1++;
        }
    }

    int num_total_pairs = n / 2;
    int num_bad_pairs_needed = num_total_pairs - k;

    // Zeros and ones needed for these bad pairs
    int zeros_for_bad = num_bad_pairs_needed;
    int ones_for_bad = num_bad_pairs_needed;

    if (count0 < zeros_for_bad || count1 < ones_for_bad) {
        std::cout << "NO" << std::endl;
        return;
    }

    // Remaining zeros and ones are for the k good pairs
    int remaining_zeros_for_good = count0 - zeros_for_bad;
    // int remaining_ones_for_good = count1 - ones_for_bad; // Not strictly needed for check

    // As derived, remaining_zeros_for_good + remaining_ones_for_good == 2 * k.
    // For these 2k characters to form k good pairs,
    // remaining_zeros_for_good must be even (which implies remaining_ones_for_good is also even).
    
    // Also, remaining_zeros_for_good must be non-negative. This is covered by the check above.
    // (count0 >= zeros_for_bad implies remaining_zeros_for_good >= 0)

    if (remaining_zeros_for_good % 2 == 0) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
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