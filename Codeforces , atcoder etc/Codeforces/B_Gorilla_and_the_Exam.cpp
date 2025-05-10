#include <iostream>
#include <vector>
#include <map>
#include <algorithm> // For sort

void solve() {
    int n;
    int k; 
    std::cin >> n >> k;
    std::map<int, int> counts;
    for (int i = 0; i < n; ++i) {
        int val; 
        std::cin >> val;
        counts[val]++;
    }

    // counts cannot be empty because problem constraints state 1 <= n <= 10^5.

    std::vector<int> freqs_values;
    for (auto const& pair : counts) { 
        freqs_values.push_back(pair.second);
    }

    // Sort frequencies in descending order to pick the most common ones first.
    std::sort(freqs_values.rbegin(), freqs_values.rend()); 

    int current_sum_freqs = 0; 
    int ans = 0; // Stores the minimum number of distinct elements.
    
    // Iterate D from 1 up to the original number of distinct elements.
    // D represents the target number of distinct elements in the modified array.
    // freqs_values.size() is the original number of distinct elements.
    for (int D = 1; D <= static_cast<int>(freqs_values.size()); ++D) {
        // Add frequency of the D-th most common element type.
        current_sum_freqs += freqs_values[D - 1]; 
        
        // To achieve D distinct types, we keep the elements corresponding to these top D frequencies.
        // Number of elements kept = current_sum_freqs.
        // Number of elements that must be changed = n - current_sum_freqs.
        int changes_needed = n - current_sum_freqs;
        
        // If the number of changes needed is within our budget k, then D is achievable.
        // Since we iterate D in increasing order, the first D for which this is true is the minimum.
        if (changes_needed <= k) {
            ans = D;
            break; // Found the smallest D, no need to check further.
        }
    }
    // ans is guaranteed to be set. In the worst case, when D equals freqs_values.size(),
    // current_sum_freqs becomes n, so changes_needed becomes 0. Since 0 <= k (as k >= 0),
    // this condition will be met.
    
    std::cout << ans << std::endl;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}