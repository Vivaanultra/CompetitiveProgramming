#include <iostream> // For input/output operations (cin, cout)
#include <vector>   // For using std::vector dynamic arrays
#include <algorithm> // For using std::min
#include <limits>   // For using std::numeric_limits to get the maximum value for long long

// Function to check if m flowers can be collected from garden 'a'
// according to requirements 'b' without any insertions.
// This uses a greedy strategy: iterate through the garden from left to right,
// and pick the first available flower that meets the current requirement.
bool check(long long n, long long m, const std::vector<long long>& a, const std::vector<long long>& b) {
    long long current_b_idx = 0; // Index for the current requirement in b we need to satisfy
    // Iterate through the flowers in the garden 'a'
    for (long long i = 0; i < n; ++i) {
        // Check if we still have requirements left (current_b_idx < m)
        // and if the current flower a[i] meets the current beauty requirement b[current_b_idx]
        if (current_b_idx < m && a[i] >= b[current_b_idx]) {
            // If yes, we conceptually "collect" this flower for the current requirement
            current_b_idx++; // Move to the next requirement
        }
        // If the current flower doesn't meet the requirement, or we've already met all requirements,
        // we simply move to the next flower in the garden.
    }
    // After checking all flowers in the garden, if we have satisfied all m requirements
    // (i.e., current_b_idx has reached m), then it's possible.
    return current_b_idx == m;
}

int main() {
    // Optimize input/output operations for potentially large inputs
    std::ios_base::sync_with_stdio(false); // Disable synchronization with C-style stdio
    std::cin.tie(NULL);                   // Untie cin from cout

    int t; // Number of test cases
    std::cin >> t; // Read the number of test cases

    // Process each test case
    while (t--) {
        long long n; // Number of flowers initially in the garden
        long long m; // Number of flowers Igor wants to collect
        std::cin >> n >> m;

        // Read the beauty values of the n flowers into vector 'a'
        // Using long long because beauty values can be up to 10^9
        std::vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        // Read the minimum beauty requirements for the m collected flowers into vector 'b'
        std::vector<long long> b(m);
        for (int i = 0; i < m; ++i) {
            std::cin >> b[i];
        }

        // --- Step 1: Check if collection is possible without inserting any flower ---
        // If Igor can already collect m flowers satisfying the conditions using the original garden.
        if (check(n, m, a, b)) {
            // If yes, the minimum beauty 'k' needed for an inserted flower is 0 (no insertion needed).
            std::cout << 0 << "\n";
            continue; // Skip the rest of the logic and move to the next test case
        }

        // If we reach here, collection is impossible without insertion. We need to consider the magic wand.

        // --- Step 2: Precompute earliest possible indices (Forward Pass) ---
        // We simulate the greedy collection process from left to right.
        // `can_collect[i]` will store the index in `a` of the flower that was used to satisfy
        // the i-th requirement (b[i]) in this forward pass.
        // If requirement b[i] cannot be satisfied, can_collect[i] will be n (an invalid index).
        std::vector<long long> can_collect(m, n); // Initialize all with impossible index 'n'
        long long current_a_idx_fwd = 0; // Pointer for iterating through garden 'a'
        long long current_b_idx_fwd = 0; // Pointer for iterating through requirements 'b'
        // Perform the greedy forward pass
        while (current_a_idx_fwd < n && current_b_idx_fwd < m) {
            if (a[current_a_idx_fwd] >= b[current_b_idx_fwd]) {
                // Found a suitable flower in 'a' for the current requirement 'b'
                can_collect[current_b_idx_fwd] = current_a_idx_fwd; // Record the garden index used
                current_b_idx_fwd++; // Move to the next requirement
            }
            current_a_idx_fwd++; // Always move to the next flower in the garden
        }

        // --- Step 3: Precompute latest possible indices (Backward Pass) ---
        // We simulate a greedy collection process, but starting from the *end* of the garden
        // and satisfying the requirements from `b[m-1]` down to `b[0]`.
        // `back_pass[i]` will store the index in `a` of the flower used to satisfy
        // requirement `b[i]` in this backward pass.
        // If `b[i]` cannot be satisfied, `back_pass[i]` will be -1 (an invalid index).
        std::vector<long long> back_pass(m, -1); // Initialize all with impossible index '-1'
        long long current_a_idx_bwd = n - 1; // Pointer for iterating through garden 'a' (from right)
        long long current_b_idx_bwd = m - 1; // Pointer for iterating through requirements 'b' (from end)
        // Perform the greedy backward pass
        while (current_a_idx_bwd >= 0 && current_b_idx_bwd >= 0) {
            if (a[current_a_idx_bwd] >= b[current_b_idx_bwd]) {
                 // Found a suitable flower in 'a' for the current requirement 'b'
                back_pass[current_b_idx_bwd] = current_a_idx_bwd; // Record the garden index used
                current_b_idx_bwd--; // Move to the previous requirement (towards b[0])
            }
            current_a_idx_bwd--; // Always move to the previous flower in the garden
        }

        // --- Step 4: Find the minimum 'k' needed for insertion ---
        // The idea is to check, for each requirement `b[i]`, if we can satisfy
        // requirements `b[0...i-1]` using the forward pass result, and requirements
        // `b[i+1...m-1]` using the backward pass result, such that there's a "gap"
        // between the indices used. If such a gap exists, it means we could theoretically
        // insert a flower of beauty `k = b[i]` in that gap to satisfy the `i`-th requirement.
        // We want the minimum `b[i]` over all `i` where this is possible.

        // Initialize minimum k to the largest possible long long value
        long long min_k = std::numeric_limits<long long>::max();

        // Iterate through each requirement index `i` from 0 to m-1
        for (int i = 0; i < m; ++i) {
            // `last_prefix_idx`: The index in `a` used for requirement `b[i-1]` (the one just before `b[i]`).
            // If `i` is 0, there's no preceding requirement, so use -1 (an index before the start).
            long long last_prefix_idx = (i == 0) ? -1 : can_collect[i - 1];

            // `first_suffix_idx`: The index in `a` used for requirement `b[i+1]` (the one just after `b[i]`).
            // If `i` is `m-1`, there's no succeeding requirement, so use `n` (an index after the end).
            long long first_suffix_idx = (i == m - 1) ? n : back_pass[i + 1];

            // Now, check if a valid split is possible around requirement `b[i]`:
            // 1. `last_prefix_idx < n`: The prefix requirements (up to b[i-1]) must have been satisfiable.
            // 2. `first_suffix_idx >= 0`: The suffix requirements (from b[i+1] onwards) must have been satisfiable.
            // 3. `last_prefix_idx < first_suffix_idx`: Crucially, the index used for the last prefix requirement
            //    must be strictly less than the index used for the first suffix requirement. This ensures
            //    that the sequences don't overlap or touch, leaving space to insert the new flower.
            if (last_prefix_idx < n && first_suffix_idx >= 0 && last_prefix_idx < first_suffix_idx) {
                // If all conditions are met, it means we *can* potentially use an inserted flower
                // with beauty at least `b[i]` to bridge this gap and satisfy all requirements.
                // We update `min_k` with the minimum `b[i]` found so far among all valid splits.
                min_k = std::min(min_k, b[i]);
            }
        }

        // --- Step 5: Output the result ---
        if (min_k == std::numeric_limits<long long>::max()) {
            // If `min_k` was never updated from its initial maximum value,
            // it means no valid split `i` was found where insertion could help.
            // Therefore, it's impossible even with the magic wand.
            std::cout << -1 << "\n";
        } else {
            // Otherwise, `min_k` holds the minimum beauty value required for the
            // inserted flower to make the collection possible.
            std::cout << min_k << "\n";
        }
    } // End of loop through test cases

    return 0; // Indicate successful program execution
}