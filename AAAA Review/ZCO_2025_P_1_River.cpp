#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // For std::abs

// No global using namespace std;

int main() {
    // Using namespace std inside main for convenience
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Helper lambdas for integer division behaving like ceil(num/2.0) and floor(num/2.0)
    auto ceil_div2 = [](long long num) -> long long {
        if (num >= 0) {
            return (num + 1) / 2; // For num=5, (5+1)/2=3. For num=4, (4+1)/2=2.
        } else {
            return num / 2; // For num=-5, -5/2=-2. For num=-4, -4/2=-2.
        }
    };

    auto floor_div2 = [](long long num) -> long long {
        if (num >= 0) {
            return num / 2; // For num=5, 5/2=2. For num=4, 4/2=2.
        } else {
            return (num - 1) / 2; // For num=-5, (-5-1)/2=-3. For num=-4, (-4-1)/2=-2 (oops, -4/2 = -2).
                                  // Corrected: (-4-1)/2 = -2.
                                  // Actually, for num=-4, it should be -4/2 = -2.
                                  // The original logic for floor_div2 was: (num >= 0) ? num / 2 : (num - 1) / 2;
                                  // This correctly handles num=-4: (-4-1)/2 = -2.
                                  // And for num=-5: (-5-1)/2 = -3.
                                  // And for num=0: 0/2=0.
                                  // And for num<0 and even (like -4), original: (-4-1)/2 = -2.
                                  // My comment example -4 was wrong, this handles both even/odd negative numbers correctly.
        }
    };
    // Re-stating the robust floor_div2 from thought process:
    auto robust_floor_div2 = [](long long num) -> long long {
        if (num >= 0) {
            return num / 2;
        } else {
            // For negative numbers, standard integer division truncates towards zero.
            // floor(x/2) for negative x:
            // if x is even, say -4, floor(-4/2) = -2. num/2 = -2.
            // if x is odd, say -5, floor(-5/2) = -3. (num-1)/2 = (-5-1)/2 = -3.
            // So (num % 2 != 0 && num < 0) ? (num-1)/2 : num/2; also works
            // The provided (num-1)/2 for num < 0 works for both cases:
            // e.g. num = -4: (-4-1)/2 = -5/2 = -2. Correct.
            // e.g. num = -5: (-5-1)/2 = -6/2 = -3. Correct.
            return (num - 1) / 2;
        }
    };

    // Person struct defined within main
    struct Person {
        long long h, w; // Home (north), Work (south) locations
    };

    int n_people_input, m_target_input, k_locations_input;
    long long b_cost;
    cin >> n_people_input >> m_target_input >> k_locations_input >> b_cost;
    
    long long m_target = m_target_input; // Use long long for M for consistency with current_coverage
    long long k_actual_locations = k_locations_input; // Number of locations 0 to K-1

    vector<Person> people_data(n_people_input);
    for (int i = 0; i < n_people_input; ++i) {
        cin >> people_data[i].h >> people_data[i].w;
    }

    if (m_target == 0) { // If no one needs to use the bridge, T=0 works.
        cout << 0 << endl;
        return 0;
    }
    
    // The 'check' function as a lambda, capturing necessary variables
    auto check = 
        [&](long long t_candidate) -> bool {
        
        vector<pair<long long, int>> events;

        for (int i = 0; i < n_people_input; ++i) {
            long long h_i = people_data[i].h;
            long long w_i = people_data[i].w;

            long long time_boat_min = b_cost + abs(h_i - w_i);
            long long max_allowed_total_bridge_time = time_boat_min + t_candidate;
            
            long long s_target_val = max_allowed_total_bridge_time - 1; // -1 for bridge crossing time

            if (s_target_val < abs(h_i - w_i)) {
                continue; // Cannot meet condition even if L is optimally between H_i and W_i
            }

            long long sum_coords = h_i + w_i;
            
            long long l_start_person = ceil_div2(sum_coords - s_target_val);
            long long l_end_person = robust_floor_div2(sum_coords + s_target_val); // Using the robust version
            
            long long actual_L_start = max(0LL, l_start_person);
            long long actual_L_end = min(k_actual_locations - 1, l_end_person);

            if (actual_L_start <= actual_L_end) {
                events.push_back({actual_L_start, 1});
                events.push_back({actual_L_end + 1, -1});
            }
        }

        sort(events.begin(), events.end());

        long long current_coverage = 0;
        for (size_t i = 0; i < events.size(); ) {
            long long current_coord = events[i].first;

            if (current_coord >= k_actual_locations) { 
                break; 
            }

            size_t j = i;
            while (j < events.size() && events[j].first == current_coord) {
                current_coverage += events[j].second;
                j++;
            }
            
            // current_coord is a valid bridge location here (0 <= current_coord < k_actual_locations)
            if (current_coverage >= m_target) {
                return true;
            }
            
            i = j; 
        }
        return false;
    };
    
    long long low_t = 0;
    // Max T could be when bridge is far, work/home are far, B is small.
    // e.g. H=0, W=K-1, L=K-1. Bridge cost |0-(K-1)|+1+| (K-1)-(K-1)| = K-1+1 = K
    // Boat cost B + |0-(K-1)| = B+K-1
    // K <= B+K-1+T  => T >= 1.
    // Max path sum |H-L|+|L-W| is about 2K.
    // So S_target can be 2K. S_target = B+|H-W|+T-1.  2K = B+K+T-1 => T = K-B+1.
    // A safe upper bound for T is sum of max possible walk + B.
    long long high_t = 2LL * k_actual_locations + b_cost + 5; // Sufficiently large upper bound for T
    long long ans_t = high_t; // Initialize with a value indicating "not found" or max possible if needed

    while (low_t <= high_t) {
        long long mid_t = low_t + (high_t - low_t) / 2;
        if (check(mid_t)) {
            ans_t = mid_t;
            high_t = mid_t - 1; // Try for a smaller T
        } else {
            low_t = mid_t + 1; // Need a larger T
        }
    }

    cout << ans_t << endl;

    return 0;
}