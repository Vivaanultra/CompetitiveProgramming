#include <bits/stdc++.h>
using namespace std;

// Use long long for costs to avoid overflow
using ll = long long;

void solve() {
    string s;
    cin >> s;
    int n = s.length();

    // Define costs as constants for clarity
    const ll C_SWAP = 1000000000000LL;
    const ll C_REMOVE = C_SWAP + 1;

    // Create prefix count arrays for O(1) lookups
    vector<int> prefix_ones(n + 1, 0);
    vector<int> prefix_zeros(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_ones[i + 1] = prefix_ones[i] + (s[i] == '1');
        prefix_zeros[i + 1] = prefix_zeros[i] + (s[i] == '0');
    }

    // Initialize min_cost to a very large value
    ll min_cost = -1;

    // Iterate through all n+1 possible split points.
    // A split at 'i' means we keep 0s from s[0..i-1] and 1s from s[i..n-1].
    for (int i = 0; i <= n; ++i) {
        // Calculate the number of misplaced characters for this split
        int ones_in_prefix = prefix_ones[i];
        int zeros_in_suffix = prefix_zeros[n] - prefix_zeros[i];
        
        // Calculate the cost assuming we only remove these misplaced characters
        ll current_cost = (ll)(ones_in_prefix + zeros_in_suffix) * C_REMOVE;

        // Update the overall minimum cost
        if (min_cost == -1 || current_cost < min_cost) {
            min_cost = current_cost;
        }

        // Check for the special swap optimization case
        // This occurs if the split is right between a '1' and a '0'
        if (i > 0 && i < n && s[i - 1] == '1' && s[i] == '0') {
            // Cost if we swap s[i-1] and s[i] instead of removing them
            ll cost_with_swap = (ll)(ones_in_prefix - 1 + zeros_in_suffix - 1) * C_REMOVE + C_SWAP;
            if (cost_with_swap < min_cost) {
                min_cost = cost_with_swap;
            }
        }
    }

    cout << min_cost << endl;
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