#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> p(n);
    std::vector<bool> present(n + 1, false);
    std::vector<int> zero_indices;

    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
        if (p[i] != 0) {
            present[p[i]] = true;
        } else {
            zero_indices.push_back(i + 1); // Use 1-based indexing for logic
        }
    }

    // Find the range of fixed mismatches (where p[i] is non-zero and not i+1)
    int l_fix = n + 1;
    int r_fix = 0;
    for (int i = 0; i < n; ++i) {
        if (p[i] != 0 && p[i] != i + 1) {
            l_fix = std::min(l_fix, i + 1);
            r_fix = std::max(r_fix, i + 1);
        }
    }

    // Case 1: No zeros to fill. Cost is determined by fixed mismatches only.
    if (zero_indices.empty()) {
        if (r_fix == 0) { // No fixed mismatches means the array is sorted
            std::cout << 0 << std::endl;
        } else {
            std::cout << r_fix - l_fix + 1 << std::endl;
        }
        return;
    }

    // Case 2: One zero to fill.
    if (zero_indices.size() == 1) {
        int z_idx = zero_indices[0];
        int m_num = -1;
        // Find the single missing number
        for (int i = 1; i <= n; ++i) {
            if (!present[i]) {
                m_num = i;
                break;
            }
        }

        if (z_idx == m_num) {
            // Forced match: p[z_idx] must be z_idx. No new mismatch created.
            if (r_fix == 0) {
                std::cout << 0 << std::endl;
            } else {
                std::cout << r_fix - l_fix + 1 << std::endl;
            }
        } else {
            // New mismatch at z_idx. Combine ranges.
            int final_l = std::min(l_fix, z_idx);
            int final_r = std::max(r_fix, z_idx);
            std::cout << final_r - final_l + 1 << std::endl;
        }
        return;
    }

    // Case 3: More than one zero. We can always create mismatches at the ends.
    int l_zero = zero_indices.front();
    int r_zero = zero_indices.back();
    
    int final_l = std::min(l_fix, l_zero);
    int final_r = std::max(r_fix, r_zero);

    std::cout << final_r - final_l + 1 << std::endl;
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