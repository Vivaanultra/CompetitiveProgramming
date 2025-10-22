#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

// Standard competitive programming setup
#include <bits/stdc++.h>
using namespace std;

// Function to solve a single test case
void solve() {
    int n;
    cin >> n;
    vector<int> x(n);
    // Use a map to store the 1-based indices of each number's occurrences
    map<int, vector<int>> positions;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        positions[x[i]].push_back(i + 1);
    }

    // Initialize with a default valid answer.
    // The minimum possible score is 1 (pick any number and play for one round).
    int best_a = x[0];
    int best_l = 1;
    int best_r = 1;
    int max_score = 1;

    // Iterate through each unique number and its list of positions
    for (auto const& [val, pos_vec] : positions) {
        // The score for a single occurrence is always 1.
        // We only need to check numbers that appear at least twice.
        if (pos_vec.size() < 2) {
            continue;
        }

        // We want to maximize: (2j - p_j) - (2i - p_i) + 1
        // where i and j are 1-based indices into pos_vec.

        // `min_val` stores the minimum value of `2*i - p_i` found so far.
        // `min_start_pos` stores the actual position `p_i` that gave this minimum.
        int min_val = 2 * 1 - pos_vec[0];
        int min_start_pos = pos_vec[0];
        
        // Loop through the occurrences (starting from the second) to find the best range
        for (size_t j = 1; j < pos_vec.size(); ++j) {
            // `current_val` corresponds to `2*(j+1) - pos_vec[j]`
            int current_val = 2 * (int)(j + 1) - pos_vec[j];
            int current_score = current_val - min_val + 1;

            if (current_score > max_score) {
                max_score = current_score;
                best_a = val;
                best_l = min_start_pos;
                best_r = pos_vec[j];
            }

            // Update the minimum starting value if a better one is found
            if (current_val < min_val) {
                min_val = current_val;
                min_start_pos = pos_vec[j];
            }
        }
    }

    cout << best_a << " " << best_l << " " << best_r << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}