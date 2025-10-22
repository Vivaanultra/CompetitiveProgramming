#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    map<int, int> counts;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        counts[x]++;
    }

    // Step 1: Filter for candidate numbers
    vector<int> candidates;
    for (auto const& [num, count] : counts) {
        if (count >= k) {
            candidates.push_back(num);
        }
    }

    if (candidates.empty()) {
        cout << -1 << endl;
        return;
    }

    // Step 2: Find the longest consecutive run
    // The `sort` is implicitly done by using a map, but we'll sort just to be explicit
    // In this case, `candidates` is already sorted because we iterate through the map.

    int best_l = -1, best_r = -1;
    int max_len = -1;

    int current_l = candidates[0];
    int current_len = 1;

    for (size_t i = 1; i < candidates.size(); ++i) {
        if (candidates[i] == candidates[i - 1] + 1) {
            // The run continues
            current_len++;
        } else {
            // The run is broken, check if it was the best one
            if (current_len > max_len) {
                max_len = current_len;
                best_l = current_l;
                best_r = candidates[i - 1];
            }
            // Start a new run
            current_l = candidates[i];
            current_len = 1;
        }
    }

    // Check the very last run
    if (current_len > max_len) {
        max_len = current_len;
        best_l = current_l;
        best_r = candidates.back();
    }

    cout << best_l << " " << best_r << endl;
}

int main() {
    // It is currently Sunday, 6:36 PM in Mathura, India.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}