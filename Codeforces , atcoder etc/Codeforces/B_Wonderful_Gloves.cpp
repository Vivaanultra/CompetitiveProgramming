#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // For std::accumulate if used, not strictly needed here

long long solve() {
    int n;
    long long k_val; // Using k_val to avoid conflict with common loop iterator k
    std::cin >> n >> k_val;
    std::vector<long long> l(n), r(n);
    for (int i = 0; i < n; ++i) std::cin >> l[i];
    for (int i = 0; i < n; ++i) std::cin >> r[i];

    long long total_max_val = 0;
    std::vector<long long> min_vals;
    min_vals.reserve(n); 

    for (int i = 0; i < n; ++i) {
        total_max_val += std::max(l[i], r[i]);
        min_vals.push_back(std::min(l[i], r[i]));
    }

    // Sort min_vals in descending order to easily pick the largest k-1 values
    std::sort(min_vals.rbegin(), min_vals.rend()); 

    long long sum_top_k_minus_1_mins = 0;
    // Sum the top k_val-1 minimums.
    // If k_val is 1, k_val-1 is 0, so the loop doesn't run, sum remains 0.
    for (int i = 0; i < k_val - 1; ++i) {
        // min_vals has n elements. Since k_val <= n, if k_val-1 > 0, then k_val-1 < n.
        // So min_vals[i] is a valid access for i from 0 to k_val-2.
        sum_top_k_minus_1_mins += min_vals[i];
    }
    
    long long m_worst = total_max_val + sum_top_k_minus_1_mins;
    return m_worst + 1;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        std::cout << solve() << std::endl;
    }
    return 0;
}