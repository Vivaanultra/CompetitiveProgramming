#include <iostream>
#include <vector>
#include <numeric>

// Function to handle a single test case
void solve() {
    long long n, m;
    std::cin >> n >> m;
    
    // Store requirements
    std::vector<std::pair<long long, long long>> reqs(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> reqs[i].first >> reqs[i].second;
    }
    
    // Initialize variables for tracking progress.
    // These represent the state at the end of the last processed interval,
    // starting with the initial state of the Pacer Test.
    long long total_points = 0;
    long long prev_time = 0;
    long long prev_side = 0;
    
    // Iterate through each requirement to calculate max points between intervals
    for (const auto& req : reqs) {
        long long current_time = req.first;
        long long required_side = req.second;
        
        // Duration of the current interval
        long long duration = current_time - prev_time;
        
        // To reach required_side from prev_side in 'k' runs,
        // the parity of k must match the parity of the side change.
        // If sides are the same, k must be even. If different, k must be odd.
        // This is equivalent to checking if (k % 2) == (prev_side != required_side).
        bool required_k_parity_is_odd = (prev_side != required_side);
        
        // The parity of the duration (max possible runs)
        bool duration_is_odd = (duration % 2 != 0);
        
        long long points_this_interval;
        if (duration_is_odd == required_k_parity_is_odd) {
            // If duration has the correct parity, we can run every minute.
            points_this_interval = duration;
        } else {
            // Otherwise, we must skip one run to match the required parity.
            points_this_interval = duration - 1;
        }
        
        // Add the points from this interval to the total
        total_points += points_this_interval;
        
        // Update the state for the next interval
        prev_time = current_time;
        prev_side = required_side;
    }
    
    // After the last requirement, FJ can run every minute until the end.
    total_points += (m - prev_time);
    
    std::cout << total_points << std::endl;
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