#include <iostream>
#include <vector>
#include <algorithm> // For std::sort, std::unique, std::min_element, std::max_element
#include <set>       // Can also be used for unique elements

// Function to check if a (potentially empty) array is fashionable
// For this problem, an empty array after removals is not considered fashionable
// as min/max are undefined. A single element array is fashionable.
bool is_array_fashionable(const std::vector<int>& current_array) {
    if (current_array.empty()) {
        return false; 
    }
    if (current_array.size() == 1) {
        return true; 
    }
    
    // Use std::minmax_element to find min and max in one pass
    auto mm_pair = std::minmax_element(current_array.begin(), current_array.end());
    int min_val = *mm_pair.first;
    int max_val = *mm_pair.second;
    
    return (min_val + max_val) % 2 == 0;
}

int solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    if (n == 0) { // As per constraints 1 <= n, this case won't occur from input
        return 0;
    }
    if (n == 1) { // A single element array is always fashionable
        return 0;
    }

    // Create a sorted list of unique elements from 'a'
    // These are the candidates for the min and max of the final fashionable array
    std::vector<int> unique_elements_in_a = a;
    std::sort(unique_elements_in_a.begin(), unique_elements_in_a.end());
    unique_elements_in_a.erase(std::unique(unique_elements_in_a.begin(), unique_elements_in_a.end()), unique_elements_in_a.end());

    int m = unique_elements_in_a.size();
    
    // Initialize min_ops. Max possible ops is n-1 (reduce to a single element).
    // If the original array is already fashionable, this will be updated to 0.
    int min_total_ops = n - 1; 


    // Iterate over all possible pairs of (candidate_min, candidate_max)
    // from the unique elements present in the original array.
    for (int i = 0; i < m; ++i) {
        int val_min_candidate = unique_elements_in_a[i];
        for (int j = i; j < m; ++j) {
            int val_max_candidate = unique_elements_in_a[j];

            // Check if the chosen min and max candidates themselves have a sum of correct parity
            if ((val_min_candidate + val_max_candidate) % 2 != 0) {
                continue; 
            }

            int current_removals = 0;
            // Count elements from the original array 'a' that would be removed
            // if we enforce val_min_candidate and val_max_candidate as min/max.
            // This means removing elements smaller than val_min_candidate
            // or larger than val_max_candidate.
            for (int k = 0; k < n; ++k) {
                if (a[k] < val_min_candidate || a[k] > val_max_candidate) {
                    current_removals++;
                }
            }
            
            // The number of elements remaining would be n - current_removals.
            // If n - current_removals is 0, it means this choice of min/max
            // leads to an empty array, which is not fashionable.
            // The initial min_total_ops = n - 1 already covers making a single-element array,
            // so if current_removals = n, it won't be chosen over n-1 unless n=0 or n=1.
            // For n >= 1, if current_removals = n, then n - current_removals = 0 (empty).
            // We only update min_total_ops if this choice is valid (results in non-empty array).
            // This strategy ensures the remaining array would have its min >= val_min_candidate
            // and max <= val_max_candidate. By choosing candidates from unique_elements_in_a,
            // if the remaining set is non-empty, val_min_candidate and val_max_candidate
            // (or values between them from 'a') will form the new min/max.
            
            if (n - current_removals > 0) { // Ensure the resulting array is not empty
                 min_total_ops = std::min(min_total_ops, current_removals);
            } else if (n == 0 && current_removals == 0) { // Special case if n=0 was allowed
                 min_total_ops = std::min(min_total_ops, 0);
            }
        }
    }
    
    // Check the 0-operation case explicitly for clarity, though the loop above should find it.
    if (is_array_fashionable(a)) {
        min_total_ops = std::min(min_total_ops, 0);
    }


    return min_total_ops;
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
