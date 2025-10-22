#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void solve() {
    int n;
    long long k;
    std::cin >> n >> k;
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    // Sort ascending to empty the smallest slots first
    std::sort(a.begin(), a.end());

    long long total_presses = 0;
    long long cans_collected = 0;
    long long last_emptied_level = 0;

    for (int i = 0; i < n; ++i) {
        // At the start of phase `i`, we know `i` slots are empty.
        long long num_live_slots = n - i;
        long long cans_to_empty_this_level = a[i] - last_emptied_level;

        if (cans_to_empty_this_level == 0) {
            continue; // Handles slots with the same initial amount
        }

        long long potential_cans_this_phase = cans_to_empty_this_level * num_live_slots;

        if (cans_collected + potential_cans_this_phase >= k) {
            // We will reach our target in this phase.
            long long cans_still_needed = k - cans_collected;
            
            // In the worst case, to get the cans we need, we first
            // press all `i` buttons that were already dead from previous phases.
            total_presses += (cans_still_needed + i);
            cans_collected = k; // Target reached
            break;
        } else {
            // We complete the entire phase without reaching k.
            total_presses += potential_cans_this_phase;
            cans_collected += potential_cans_this_phase;
            last_emptied_level = a[i];
        }
    }

    std::cout << total_presses << std::endl;
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