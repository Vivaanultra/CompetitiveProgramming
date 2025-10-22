#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For std::lower_bound, std::upper_bound, std::max, std::min

// Helper to map char types to int (F=0, W=1, G=2)
int type_to_int(char c) {
    if (c == 'F') return 0;
    if (c == 'W') return 1;
    if (c == 'G') return 2;
    return -1; 
}

// Define relationships: Beats[X] is type that beats X. XBeats[X] is type X beats.
int Beats[3];
int XBeats[3];

// Helper function to count monsters of a specific type in a range [l, r] (0-indexed)
// using precomputed prefix sums.
int count_type_in_range(int type_val, int l, int r, const std::vector<std::vector<int>>& pref_counts) {
    if (l > r) return 0; // Empty range
    return pref_counts[type_val][r + 1] - pref_counts[type_val][l];
}

// Helper function to get first occurrence of type in [L0, R0]
// Returns R0 + 1 if not found.
int get_first_occurrence(int type_val, int L0, int R0, const std::vector<std::vector<int>>& indices_by_type) {
    const auto& specific_type_indices = indices_by_type[type_val];
    auto it = std::lower_bound(specific_type_indices.begin(), specific_type_indices.end(), L0);
    if (it == specific_type_indices.end() || *it > R0) {
        return R0 + 1; 
    }
    return *it;
}

// Helper function to get last occurrence of type in [L0, R0]
// Returns L0 - 1 if not found.
int get_last_occurrence(int type_val, int L0, int R0, const std::vector<std::vector<int>>& indices_by_type) {
    const auto& specific_type_indices = indices_by_type[type_val];
    auto it = std::upper_bound(specific_type_indices.begin(), specific_type_indices.end(), R0);
    if (it == specific_type_indices.begin()) {
        return L0 - 1; 
    }
    --it; 
    if (*it < L0) {
        return L0 - 1; 
    }
    return *it;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Setup type relationships
    Beats[type_to_int('F')] = type_to_int('W');
    Beats[type_to_int('W')] = type_to_int('G');
    Beats[type_to_int('G')] = type_to_int('F');

    XBeats[type_to_int('F')] = type_to_int('G');
    XBeats[type_to_int('W')] = type_to_int('F');
    XBeats[type_to_int('G')] = type_to_int('W');

    int N;
    std::cin >> N;
    std::string A_str;
    std::cin >> A_str;

    // Precomputation
    std::vector<std::vector<int>> pref_counts(3, std::vector<int>(N + 1, 0));
    std::vector<std::vector<int>> indices_by_type(3);

    for (int i = 0; i < N; ++i) {
        int current_monster_type_int = type_to_int(A_str[i]);
        for (int type_val = 0; type_val < 3; ++type_val) {
            pref_counts[type_val][i + 1] = pref_counts[type_val][i];
        }
        pref_counts[current_monster_type_int][i + 1]++;
        indices_by_type[current_monster_type_int].push_back(i);
    }

    int Q_val;
    std::cin >> Q_val;
    while (Q_val--) {
        int L_query, R_query;
        std::cin >> L_query >> R_query;
        int L0 = L_query - 1; // 0-indexed
        int R0 = R_query - 1; // 0-indexed

        long long total_possible_winners = 0;

        for (int current_type_val = 0; current_type_val < 3; ++current_type_val) {
            int num_current_type_in_query_range = count_type_in_range(current_type_val, L0, R0, pref_counts);
            if (num_current_type_in_query_range == 0) {
                continue;
            }

            int S_type = Beats[current_type_val]; // Type that beats current_type_val
            int P_type = XBeats[current_type_val]; // Type that current_type_val beats (and P_type beats S_type)

            bool S_type_present = count_type_in_range(S_type, L0, R0, pref_counts) > 0;
            
            if (!S_type_present) { // Rule 1: No threats
                total_possible_winners += num_current_type_in_query_range;
            } else { // S_type (threats) are present
                bool P_type_present = count_type_in_range(P_type, L0, R0, pref_counts) > 0;
                if (!P_type_present) { // Rule 2: Threats present, but no helpers (P_type)
                    // No monster of current_type_val can win. Add 0.
                } else { // Rule 3: Both S_type and P_type are present
                    int s_f = get_first_occurrence(S_type, L0, R0, indices_by_type); 
                    int p_f = get_first_occurrence(P_type, L0, R0, indices_by_type); 
                    int s_l = get_last_occurrence(S_type, L0, R0, indices_by_type);   
                    int p_l = get_last_occurrence(P_type, L0, R0, indices_by_type);   

                    // Losing Condition A: idx_k in (s_f, p_f]
                    int r1_L = s_f + 1;
                    int r1_R = p_f;
                    r1_L = std::max(L0, r1_L); r1_R = std::min(R0, r1_R);

                    // Losing Condition B: idx_k in [p_l, s_l)
                    int r2_L = p_l;
                    int r2_R = s_l - 1;
                    r2_L = std::max(L0, r2_L); r2_R = std::min(R0, r2_R);
                    
                    int losers1_count = count_type_in_range(current_type_val, r1_L, r1_R, pref_counts);
                    int losers2_count = count_type_in_range(current_type_val, r2_L, r2_R, pref_counts);
                    
                    // Intersection of Range1 and Range2
                    int intersect_L = std::max(r1_L, r2_L);
                    int intersect_R = std::min(r1_R, r2_R);
                    int intersect_count = count_type_in_range(current_type_val, intersect_L, intersect_R, pref_counts);

                    int num_losers = losers1_count + losers2_count - intersect_count;
                    total_possible_winners += (num_current_type_in_query_range - num_losers);
                }
            }
        }
        std::cout << total_possible_winners << "\n";
    }

    return 0;
}