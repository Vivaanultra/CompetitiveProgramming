#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long c;
    cin >> n >> c;
    vector<long long> a(n);
    vector<pair<long long, int>> base_costs(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        // 0-based index i corresponds to position i+1
        // Distance from 0 is i+1
        // Distance from n+1 is (n+1) - (i+1) = n - i
        long long cost = a[i] + min((long long)i + 1, (long long)n - i);
        base_costs[i] = {cost, i};
    }

    // Sort by base cost to allow greedy selection
    sort(base_costs.begin(), base_costs.end());

    // Create prefix sums for fast calculation
    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + base_costs[i].first;
    }

    // Map original index to position in sorted array
    vector<int> pos_in_sorted(n);
    for (int i = 0; i < n; i++) {
        pos_in_sorted[base_costs[i].second] = i;
    }

    int max_teleporters = 0;

    // Try every teleporter as the "start" teleporter (forced from 0)
    for (int i = 0; i < n; i++) {
        long long start_cost = a[i] + (i + 1);
        
        if (c < start_cost) continue;
        
        long long budget = c - start_cost;
        
        // We want to find max k such that we can buy k items from base_costs
        // (excluding the current item i which we already bought).
        // We binary search for the number of EXTRA items we can buy.
        
        int left = 0, right = n - 1; 
        int count = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Calculate cost to buy 'mid' cheapest items excluding 'i'
            long long current_pref_cost = 0;
            
            // Check if item i is within the first 'mid' items in the sorted list
            // Note: We need 'mid' items. 
            // If pos_in_sorted[i] < mid, then i is inside the cheapest block.
            // We need to take prefix of size (mid + 1) and subtract i.
            // If pos_in_sorted[i] >= mid, i is outside. We just take prefix of size mid.
            
            if (pos_in_sorted[i] < mid) {
                // i is among the cheapest 'mid' items, so we take mid+1 and remove i
                if (mid + 1 <= n)
                    current_pref_cost = pref[mid + 1] - base_costs[pos_in_sorted[i]].first;
                else 
                    current_pref_cost = 2e18; // Infinite cost, can't take
            } else {
                // i is not among them, just take the top 'mid'
                current_pref_cost = pref[mid];
            }
            
            if (current_pref_cost <= budget) {
                count = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        max_teleporters = max(max_teleporters, 1 + count);
    }

    cout << max_teleporters << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}