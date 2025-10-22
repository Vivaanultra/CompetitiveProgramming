#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

// Use fast I/O
void fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    // Edge case for n=2, both are always possible
    if (n == 2) {
        std::cout << "11\n";
        return;
    }

    // Step 1: Precompute prefix minimums and suffix maximums
    std::vector<int> min_pref(n);
    min_pref[0] = a[0];
    for (int i = 1; i < n; ++i) {
        min_pref[i] = std::min(min_pref[i - 1], a[i]);
    }

    std::vector<int> max_suff(n);
    max_suff[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        max_suff[i] = std::max(max_suff[i + 1], a[i]);
    }

    // Step 2: Find all possible achievable values and store in a hash set
    std::unordered_set<int> possible_values;

    // Case 1: 2-element intermediate array [min_pref, max_suff]
    // Iterate through all possible split points between i and i+1
    for (int i = 0; i < n - 1; ++i) {
        int pref_min = min_pref[i];
        int suff_max = max_suff[i + 1];
        possible_values.insert(std::min(pref_min, suff_max));
        possible_values.insert(std::max(pref_min, suff_max));
    }
    
    // Case 2: 3-element intermediate array [min_pref, a[i], max_suff]
    // Iterate through each element a[i] as the isolated middle one
    for (int i = 0; i < n; ++i) {
        int pref_min = (i > 0) ? min_pref[i - 1] : 2e9; // Effectively infinity
        int suff_max = (i < n - 1) ? max_suff[i + 1] : -1; // Effectively -infinity
        
        // The min of these 3 elements is already covered by the 2-element case
        // We only need to consider the max
        int val = a[i];
        if (pref_min > val && suff_max > val) {
             possible_values.insert(std::max(pref_min, suff_max));
        } else if (pref_min > val) {
             possible_values.insert(std::max(pref_min, val));
        } else if (suff_max > val) {
             possible_values.insert(std::max(suff_max, val));
        } else {
             possible_values.insert(val);
        }
    }


    // Step 3: Build the result string
    std::string ans = "";
    for (int i = 0; i < n; ++i) {
        if (possible_values.count(a[i])) {
            ans += '1';
        } else {
            ans += '0';
        }
    }
    std::cout << ans << "\n";
}

int main() {
    fast_io();
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}