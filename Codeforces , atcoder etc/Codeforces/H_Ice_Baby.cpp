#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> ranges(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> ranges[i].first >> ranges[i].second;
    }

    // dp[len] = minimum end value of an LNDS of length 'len'
    std::map<int, int> dp;

    for (int k = 0; k < n; ++k) {
        int lk = ranges[k].first;
        int rk = ranges[k].second;

        // Find the first LNDS that we cannot extend with a value strictly less than lk.
        // `it` points to an LNDS (len, val) where val >= lk.
        auto it = dp.lower_bound(lk);
        
        int len = 0;
        // If `it` is not the beginning, the LNDS before it can be extended.
        if (it != dp.begin()) {
            len = std::prev(it)->first;
        }
        
        // We can potentially form an LNDS of length len+1.
        int new_len = len + 1;
        // Its end value must be at least lk.
        int new_val = lk;
        
        // We only care about this new LNDS if its end value is <= rk.
        if (new_val <= rk) {
            // Check if this new LNDS is better than an existing one of the same length.
            auto existing_it = dp.find(new_len);
            if (existing_it == dp.end() || new_val < existing_it->second) {
                // We found a better LNDS for this length. Insert/update it.
                dp[new_len] = new_val;
                
                // This new/updated entry might make subsequent entries redundant.
                // An entry (l, v) is redundant if there's an entry (l_prev, v_prev)
                // with l_prev < l and v_prev <= v.
                // Since our map is sorted, we just need to check if new_val >= next_val.
                auto it_to_rem = dp.find(new_len);
                if (it_to_rem != dp.end()) {
                    ++it_to_rem;
                    while (it_to_rem != dp.end() && it_to_rem->second <= new_val) {
                        it_to_rem = dp.erase(it_to_rem);
                    }
                }
            }
        }
        
        // The answer for prefix k is the current max length found.
        std::cout << dp.rbegin()->first << (k == n - 1 ? "" : " ");
    }
    std::cout << "\n";
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