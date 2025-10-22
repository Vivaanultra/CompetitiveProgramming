#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int max_r = 0;
    vector<vector<pair<int, int>>> ends_at(2 * n + 1);
    for(int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        ends_at[r].push_back({l, i + 1});
        max_r = max(max_r, r);
    }
    
    vector<long long> dp(max_r + 1, 0);
    // parent[i] stores {previous_endpoint, segment_index} for backtracking
    vector<pair<int, int>> parent(max_r + 1); 

    for(int i = 1; i <= max_r; ++i) {
        // Option 1: Inherit score from previous position
        dp[i] = dp[i-1];
        parent[i] = {i - 1, -1}; // -1 indicates no segment was chosen

        // Option 2: Check if adding a segment ending at `i` is better
        for(auto const& seg : ends_at[i]) {
            int l = seg.first;
            int original_idx = seg.second;
            long long score_if_chosen = dp[l] + (i - l);
            if (score_if_chosen > dp[i]) {
                dp[i] = score_if_chosen;
                parent[i] = {l, original_idx};
            }
        }
    }
    
    vector<int> chosen_indices;
    int curr = max_r;
    while(curr > 0) {
        int prev_pos = parent[curr].first;
        int seg_idx = parent[curr].second;

        if (seg_idx != -1) { // A segment was chosen to end at curr
            chosen_indices.push_back(seg_idx);
        }
        curr = prev_pos;
    }
    
    reverse(chosen_indices.begin(), chosen_indices.end());

    cout << chosen_indices.size() << endl;
    for(size_t i = 0; i < chosen_indices.size(); ++i) {
        cout << chosen_indices[i] << (i == chosen_indices.size() - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    // It is currently Wednesday, 8:36 PM in Mathura, India.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}