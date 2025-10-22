#include <iostream>
#include <vector>
#include <set>       // For storing distinct elements
#include <algorithm> // For std::lower_bound, std::max

// Fast I/O
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

    if (n == 0) {
        std::cout << 0 << "\n";
        return;
    }

    // Precompute positions of each number.
    // positions_vec[k] stores a sorted list of 0-based indices where value k appears.
    // Values a[i] are 1-indexed (1 to n), so vector size n+1.
    std::vector<std::vector<int>> positions_vec(n + 1);
    for (int i = 0; i < n; ++i) {
        positions_vec[a[i]].push_back(i);
    }

    // Lambda to find the next occurrence of val_to_find at or after min_idx_search
    auto get_next_occurrence = 
        [&](int val_to_find, int min_idx_search) -> int {
        // Values are 1 to n. If val_to_find is outside this or never appeared,
        // it's effectively not found.
        if (val_to_find < 1 || val_to_find > n || positions_vec[val_to_find].empty()) {
            return n; // Sentinel for "not found in the relevant part of the array"
        }
        
        const auto& pos_list = positions_vec[val_to_find];
        
        auto it_list = std::lower_bound(pos_list.begin(), pos_list.end(), min_idx_search);
        
        if (it_list == pos_list.end()) {
            return n; // No occurrence at or after min_idx_search
        }
        return *it_list; // Return the 0-based index of the occurrence
    };

    int num_segments = 0;
    // Stores distinct elements from the *previous* segment (b_j),
    // which must all be present in the *current* segment (b_{j+1}).
    std::set<int> distinct_elements_to_cover; 
    
    int current_segment_start_idx = 0; // Start index in 'a' for the current segment

    while (current_segment_start_idx < n) {
        // The current segment must span its first element.
        int current_segment_end_idx = current_segment_start_idx;

        bool possible_to_form_segment = true;
        // If it's not the first segment, ensure elements from previous segment are covered.
        if (!distinct_elements_to_cover.empty()) {
            for (int val_needed : distinct_elements_to_cover) {
                int occurrence_idx = get_next_occurrence(val_needed, current_segment_start_idx);
                
                if (occurrence_idx >= n) { // If occurrence_idx == n, it means not found or out of bounds
                    possible_to_form_segment = false;
                    break;
                }
                // The current segment must extend at least to this occurrence_idx.
                current_segment_end_idx = std::max(current_segment_end_idx, occurrence_idx);
            }
        }

        if (!possible_to_form_segment) {
            // Cannot satisfy condition. Current num_segments is the max.
            break;
        }
        
        num_segments++; // Successfully formed one more segment.
        
        // The segment just formed is a[current_segment_start_idx ... current_segment_end_idx].
        // Collect its distinct elements; these must be covered by the *next* segment.
        distinct_elements_to_cover.clear(); 
        for (int k_idx = current_segment_start_idx; k_idx <= current_segment_end_idx; ++k_idx) {
            distinct_elements_to_cover.insert(a[k_idx]);
        }
        
        // Advance to the start of the next potential segment.
        current_segment_start_idx = current_segment_end_idx + 1;
    }

    std::cout << num_segments << "\n";
}

int main() {
    fast_io(); // Apply fast I/O settings

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}