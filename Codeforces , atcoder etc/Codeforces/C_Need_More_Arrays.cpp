#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    if (n == 0) {
        std::cout << 0 << std::endl;
        return;
    }

    std::map<int, int> dp_map; // Stores dp[value]
    std::map<int, int> prefix_max_map; // Stores max(dp[k]) for k <= value, only at points where max increases
    int overall_max_groups = 0;

    for (int i = 0; i < n; ++i) {
        int x = a[i];
        int current_dp_for_x = 1; // Base case: x is the first element in its subsequence

        // Option 1: x starts a new group
        // It follows some prev_val <= x - 2. Max groups = dp[prev_val] + 1.
        // We need max(dp[k]) for k <= x - 2. This is found from prefix_max_map.
        if (x - 2 >= 1) {
            auto it = prefix_max_map.upper_bound(x - 2);
            int max_score_for_new_group_prev = 0;
            if (it != prefix_max_map.begin()) {
                it--; // Point to the largest key <= x - 2
                max_score_for_new_group_prev = it->second;
            }
            if (max_score_for_new_group_prev > 0) { // If any such prefix exists
                current_dp_for_x = std::max(current_dp_for_x, max_score_for_new_group_prev + 1);
            }
        }

        // Option 2: x continues an existing group
        // It follows prev_val = x - 1 or prev_val = x (from a previous a[k]=x).
        // Max groups = dp[prev_val].
        int score_continuing_group = 0;
        if (dp_map.count(x - 1)) {
            score_continuing_group = std::max(score_continuing_group, dp_map.at(x - 1));
        }
        if (dp_map.count(x)) { // If x was already processed (e.g. a=[...,X,...,X,...])
            score_continuing_group = std::max(score_continuing_group, dp_map.at(x));
        }
        current_dp_for_x = std::max(current_dp_for_x, score_continuing_group);
        
        // Update dp_map[x] if current_dp_for_x is better
        bool dp_val_updated = false;
        if (!dp_map.count(x) || current_dp_for_x > dp_map.at(x)) {
            dp_map[x] = current_dp_for_x;
            dp_val_updated = true;
        }
        
        // If dp_map[x] was updated, try to update prefix_max_map
        if (dp_val_updated) {
            int prev_actual_prefix_max = 0;
            auto it_pm_prev = prefix_max_map.upper_bound(x - 1); // Iterator to first key > x-1
            if (it_pm_prev != prefix_max_map.begin()) {
                it_pm_prev--; // Iterator to largest key <= x-1
                prev_actual_prefix_max = it_pm_prev->second;
            }

            int new_prefix_max_at_x = std::max(prev_actual_prefix_max, dp_map.at(x));

            if (new_prefix_max_at_x > prev_actual_prefix_max) {
                prefix_max_map[x] = new_prefix_max_at_x;
                
                // Clean up entries in prefix_max_map that are now "dominated"
                auto it_to_clean = prefix_max_map.upper_bound(x); // First key > x
                while (it_to_clean != prefix_max_map.end() && it_to_clean->second <= new_prefix_max_at_x) {
                    it_to_clean = prefix_max_map.erase(it_to_clean); // C++11 erase returns next iterator
                }
            }
        }
        overall_max_groups = std::max(overall_max_groups, dp_map.at(x));
    }

    std::cout << overall_max_groups << std::endl;
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