#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Use long long for values that can exceed 2^31 - 1
using ll = long long;

const int MAX_VAL = 1000000;

int main() {
    // Optimize I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    ll total_initial_water = 0;
    
    // counts[v] will store the number of available upgrades that provide a reduction of 'v' water.
    // Index corresponds to value, so size is MAX_VAL + 1.
    vector<ll> counts(MAX_VAL + 2, 0);

    for (int i = 0; i < n; ++i) {
        // Calculate initial total water usage
        total_initial_water += (ll)a[i] * b[i];
        
        // For each vegetable, we can perform min(A, B) operations.
        // Each operation reduces the cost by max(A, B).
        int val = max(a[i], b[i]);
        int amt = min(a[i], b[i]);
        
        counts[val] += amt;
    }

    // Precompute suffix sums (conceptually prefix sums from the right/largest value)
    // p_ops[v] = Total number of upgrades available with value >= v
    // p_val[v] = Total water reduction achievable using all upgrades with value >= v
    vector<ll> p_ops(MAX_VAL + 2, 0);
    vector<ll> p_val(MAX_VAL + 2, 0);

    for (int v = MAX_VAL; v >= 1; --v) {
        p_ops[v] = p_ops[v + 1] + counts[v];
        p_val[v] = p_val[v + 1] + (ll)counts[v] * v;
    }

    for (int j = 0; j < q; ++j) {
        ll x;
        cin >> x;

        // If X is greater than total available upgrades, we use all of them.
        // The max reduction is limited by p_ops[1] (all upgrades >= 1).
        if (x >= p_ops[1]) {
            cout << 0 << "\n";
            continue;
        }

        // We want to greedily take upgrades with the highest value.
        // We find the smallest value 'v' such that we can't take ALL upgrades >= v.
        // In other words, we find the largest 'v' such that p_ops[v] > x.
        // All upgrades with value > v (i.e., index v+1) are taken fully.
        // We take the remaining needed upgrades from value v.
        
        int low = 1, high = MAX_VAL + 1;
        int v = 0; 

        // Binary search to find the "split" bucket
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // p_ops is non-increasing. We want largest index 'mid' where p_ops[mid] > x.
            if (p_ops[mid] > x) {
                v = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // Calculate reduction
        
        // 1. Take all upgrades strictly better than v (from index v+1 upwards)
        ll current_reduction = p_val[v + 1];
        
        // 2. See how many upgrades we have used so far
        ll ops_used_so_far = p_ops[v + 1];
        
        // 3. Fill the remainder of X with upgrades of value v
        ll rem_ops = x - ops_used_so_far;
        current_reduction += rem_ops * v;

        cout << (total_initial_water - current_reduction) << "\n";
    }

    return 0;
}