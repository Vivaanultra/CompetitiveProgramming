#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// Per your preference for competitive programming
#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    // Store positions using 0-based indexing for convenience
    std::vector<long long> pos(n);
    for (int i = 0; i < n; ++i) {
        int p_i;
        std::cin >> p_i;
        pos[p_i] = i;
    }

    // Precompute the min/max positions for prefixes of numbers {0, 1, ..., i}
    std::vector<long long> L(n), R(n);
    L[0] = pos[0];
    R[0] = pos[0];
    for (int i = 1; i < n; ++i) {
        L[i] = std::min(L[i - 1], pos[i]);
        R[i] = std::max(R[i - 1], pos[i]);
    }

    long long total_count = 0;

    // Iterate through all possible subsegment lengths k
    for (long long k = 1; k <= n; ++k) {
        // For length k, the condition mex >= floor((k+1)/2) must hold.
        // This means the subsegment must contain {0, ..., M-1}, where M = floor((k+1)/2).
        long long M = (k + 1) / 2;
        long long m_required = M - 1;

        // Find the bounds of the minimum subsegment containing {0, ..., m_required}
        long long l_min_pos = L[m_required];
        long long r_max_pos = R[m_required];
        long long len_needed = r_max_pos - l_min_pos + 1;

        // The subsegment must be at least this long.
        if (k < len_needed) {
            continue;
        }

        // Count how many subsegments of length k can contain the range [l_min_pos, r_max_pos].
        // Let the subsegment be [l, r] (0-indexed). l must be in [0, n-k].
        // We need: l <= l_min_pos and r >= r_max_pos.
        // r = l + k - 1, so l + k - 1 >= r_max_pos => l >= r_max_pos - k + 1.
        
        long long lower_bound_l = std::max(0LL, r_max_pos - k + 1);
        long long upper_bound_l = std::min(l_min_pos, (long long)n - k);

        if (upper_bound_l >= lower_bound_l) {
            total_count += (upper_bound_l - lower_bound_l + 1);
        }
    }

    std::cout << total_count << std::endl;
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