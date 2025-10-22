#include <bits/stdc++.h>

// Using standard namespace for competitive programming
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    
    // last_a[v] stores the last (rightmost) 1-based index where value v appears in array a.
    vector<int> last_a(n + 1, 0);
    // last_b[v] stores the last (rightmost) 1-based index where value v appears in array b.
    vector<int> last_b(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        last_a[a[i]] = i + 1;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        last_b[b[i]] = i + 1;
    }

    // Precomputing the rightmost index a value 'v' can reach in each propagation chain.
    // max_i_Sa[v] is the max index i such that v is in the set of available values for a[i].
    vector<int> max_i_Sa(n + 1, 0);
    // max_i_Sb[v] is the max index i such that v is in the set of available values for b[i].
    vector<int> max_i_Sb(n + 1, 0);

    for (int v = 1; v <= n; ++v) {
        max_i_Sa[v] = max(last_a[v], (last_b[v] > 0 ? last_b[v] - 1 : 0));
        max_i_Sb[v] = max(last_b[v], (last_a[v] > 0 ? last_a[v] - 1 : 0));
    }

    // M[i] will be true if a match is possible at index i.
    vector<bool> M(n + 2, false);
    // We iterate from right to left to build the DP state.
    // M[i] depends on M[i+1].
    for (int i = n; i >= 1; --i) {
        // Check if a[i-1] is available in the value pool for b[i]
        bool a_in_Sa_next = (i + 1 <= max_i_Sa[a[i - 1]]);
        // Check if b[i-1] is available in the value pool for a[i]
        bool b_in_Sb_next = (i + 1 <= max_i_Sb[b[i - 1]]);
        
        M[i] = (a[i - 1] == b[i - 1]) || a_in_Sa_next || b_in_Sb_next || M[i + 1];
    }

    // Calculate prefix sums of possible matches.
    vector<int> pref_ans(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        pref_ans[i] = pref_ans[i - 1] + (M[i] ? 1 : 0);
    }

    // Calculate suffix sums of possible matches.
    vector<int> suf_ans(n + 2, 0);
    for (int i = n; i >= 1; --i) {
        suf_ans[i] = suf_ans[i + 1] + (M[i] ? 1 : 0);
    }

    // The answer without any removal is the total possible matches.
    int max_matches = suf_ans[1]; 
    
    // Iterate through all possible single-removal positions k.
    for (int k = 1; k <= n; ++k) {
        // Matches if we remove k is sum of matches in prefix [1..k-1] and suffix [k+1..n].
        int current_matches = (k > 1 ? pref_ans[k - 1] : 0) + (k < n ? suf_ans[k + 1] : 0);
        if (current_matches > max_matches) {
            max_matches = current_matches;
        }
    }

    cout << max_matches << endl;
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