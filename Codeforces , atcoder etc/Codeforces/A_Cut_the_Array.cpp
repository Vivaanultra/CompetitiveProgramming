#include <iostream>
#include <vector>
#include <numeric>

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    // Calculate prefix sums modulo 3.
    // pref[i] stores the sum of the first i elements of 'a' modulo 3.
    std::vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = (pref[i] + a[i]) % 3;
    }

    int found_l = 0;
    int found_r = 0;
    bool solution_found = false;

    // Iterate through all possible split points l and r (1-based indices).
    // The loops ensure that 1 <= l < r < n, guaranteeing three non-empty parts.
    for (int l = 1; l <= n - 2; ++l) {
        for (int r = l + 1; r <= n - 1; ++r) {
            // Calculate the sums of the three parts modulo 3 using the prefix sum array.
            // s1: sum of prefix [1...l]
            // s2: sum of middle part [l+1...r]
            // s3: sum of suffix [r+1...n]
            int s1 = pref[l];
            int s2 = (pref[r] - pref[l] + 3) % 3; // Adding 3 handles negative results
            int s3 = (pref[n] - pref[r] + 3) % 3;

            // Condition 1: All three sums are the same
            bool all_same = (s1 == s2 && s2 == s3);

            // Condition 2: All three sums are different (i.e., {0, 1, 2})
            bool all_different = (s1 != s2 && s2 != s3 && s1 != s3);

            if (all_same || all_different) {
                found_l = l;
                found_r = r;
                solution_found = true;
                break; // Exit the inner loop
            }
        }
        if (solution_found) {
            break; // Exit the outer loop
        }
    }

    // Output the found indices or 0 0 if no solution exists
    std::cout << found_l << " " << found_r << std::endl;
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