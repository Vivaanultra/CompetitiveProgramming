#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>
#include <set>

// Using standard library components for competitive programming
using namespace std;

// Calculates the maximum matches for a single value 'v' based on the counts
// of its occurrences in the four parity pools (a_even, a_odd, b_even, b_odd).
long long calculate_matches_for_value(long long ae, long long ao, long long be, long long bo) {
    long long matches = 0;
    // Rule 1: Match a_even with b_even
    long long m1 = min(ae, be);
    matches += m1;
    ae -= m1;
    be -= m1;

    // Rule 2: Match a_odd with b_odd
    long long m2 = min(ao, bo);
    matches += m2;
    ao -= m2;
    bo -= m2;

    // Rule 3: Match leftover a_even with leftover a_odd
    long long m3 = min(ae, ao);
    matches += m3;
    
    // Rule 4: Match leftover b_even with leftover b_odd
    long long m4 = min(be, bo);
    matches += m4;

    return matches;
}

// Helper to get a value from a map, returning 0 if the key doesn't exist.
long long get_val(const map<int, int>& m, int key) {
    auto it = m.find(key);
    if (it == m.end()) return 0;
    return it->second;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    set<int> distinct_vals; // Use a set to efficiently track all unique values

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        distinct_vals.insert(a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        distinct_vals.insert(b[i]);
    }

    long long max_matches = 0;

    // --- Scenario 1: No removal ---
    // Calculate matches with original parities for all n elements.
    map<int, int> cae_no_rem, cao_no_rem, cbe_no_rem, cbo_no_rem;
    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 0) {
            cae_no_rem[a[i]]++;
            cbe_no_rem[b[i]]++;
        } else {
            cao_no_rem[a[i]]++;
            cbo_no_rem[b[i]]++;
        }
    }

    long long no_removal_matches = 0;
    for (int val : distinct_vals) {
        no_removal_matches += calculate_matches_for_value(
            get_val(cae_no_rem, val), get_val(cao_no_rem, val),
            get_val(cbe_no_rem, val), get_val(cbo_no_rem, val));
    }
    max_matches = no_removal_matches;

    // --- Scenario 2: Removal of an element k ---
    // We use a sliding window for the removal index k.
    // L_counts: elements before removed item k (indices 1..k-1), original parity.
    // R_counts: elements after removed item k (indices k+1..n), flipped parity.
    map<int, int> cae_L, cao_L, cbe_L, cbo_L;
    map<int, int> cae_R, cao_R, cbe_R, cbo_R;

    // Initialize for removing k=1. L group is empty, R group contains 2..n.
    for (int i = 2; i <= n; ++i) {
        if (i % 2 == 0) { cae_R[a[i]]++; cbe_R[b[i]]++; }
        else { cao_R[a[i]]++; cbo_R[b[i]]++; }
    }
    
    long long current_total_matches = 0;
    for (int val : distinct_vals) {
        // When removing k, L elements have original parity, R elements have flipped parity.
        // new_ae = cae_L + cao_R, new_ao = cao_L + cae_R, etc.
        current_total_matches += calculate_matches_for_value(
            get_val(cao_R, val), get_val(cae_R, val),
            get_val(cbo_R, val), get_val(cbe_R, val));
    }
    max_matches = max(max_matches, current_total_matches);

    // Slide the removal point k from 2 to n.
    for (int k = 2; k <= n; ++k) {
        // This loop calculates the matches when removing index k.
        // It transitions from the state of "removing k-1" to "removing k".
        
        // The values affected are a/b at k-1 (moving into L group) and k (moving out of R group).
        set<int> affected_vals;
        affected_vals.insert(a[k - 1]); affected_vals.insert(b[k - 1]);
        if (k <= n) {
             affected_vals.insert(a[k]); affected_vals.insert(b[k]);
        }
       
        // 1. Subtract the old contributions of the affected values.
        for (int val : affected_vals) {
            long long ae = get_val(cae_L, val) + get_val(cao_R, val);
            long long ao = get_val(cao_L, val) + get_val(cae_R, val);
            long long be = get_val(cbe_L, val) + get_val(cbo_R, val);
            long long bo = get_val(cbo_L, val) + get_val(cbe_R, val);
            current_total_matches -= calculate_matches_for_value(ae, ao, be, bo);
        }
        
        // 2. Update the L and R count maps to reflect the new split point.
        // Element k-1 moves into the L group (unaffected parity).
        if ((k - 1) % 2 == 0) { cae_L[a[k-1]]++; cbe_L[b[k-1]]++; }
        else { cao_L[a[k-1]]++; cbo_L[b[k-1]]++; }

        // Element k is now removed, so it exits the R group (flipped parity).
        if (k <= n) {
            if (k % 2 == 0) { cae_R[a[k]]--; cbe_R[b[k]]--; }
            else { cao_R[a[k]]--; cbo_R[b[k]]--; }
        }
        
        // 3. Add back the new contributions of the affected values.
        for (int val : affected_vals) {
            long long ae = get_val(cae_L, val) + get_val(cao_R, val);
            long long ao = get_val(cao_L, val) + get_val(cae_R, val);
            long long be = get_val(cbe_L, val) + get_val(cbo_R, val);
            long long bo = get_val(cbo_L, val) + get_val(cbe_R, val);
            current_total_matches += calculate_matches_for_value(ae, ao, be, bo);
        }
        max_matches = max(max_matches, current_total_matches);
    }
    
    cout << max_matches << endl;
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}