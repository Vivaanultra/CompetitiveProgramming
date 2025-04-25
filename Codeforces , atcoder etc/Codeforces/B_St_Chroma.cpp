#include <iostream> // Required for input (cin) and output (cout)
#include <vector>   // Useful for sequence operations, though not strictly needed here

int main() {
    // Optimize input/output operations for speed, common in competitive programming
    std::ios_base::sync_with_stdio(false); // Disable synchronization with C stdio
    std::cin.tie(NULL);                   // Untie cin from cout

    int t; // Variable to store the number of test cases
    std::cin >> t; // Read the number of test cases

    // Loop through each test case
    while (t--) {
        int n; // Variable for the length of the permutation and strip size
        int x; // Variable for the target color to maximize
        std::cin >> n >> x; // Read n and x for the current test case

        // --- Logic Explanation ---
        // We need to construct a permutation p of numbers from 0 to n-1.
        // St. Chroma paints the i-th cell (1-based index) with the color MEX(p_1, ..., p_i).
        // MEX (Minimum Excluded value) of a sequence is the smallest non-negative integer *not* present in it.
        // Goal: Construct p such that the number of cells painted with color 'x' is maximized.

        // Key observations:
        // 1. The sequence of colors generated is always non-decreasing. Because adding an element to the prefix can only keep the MEX the same or increase it.
        // 2. The color becomes 'x' exactly when the prefix {p_1, ..., p_i} contains all integers {0, 1, ..., x-1} but *does not* contain x.
        // 3. The color stops being 'x' (and becomes greater than x) as soon as 'x' is included in the prefix {p_1, ..., p_{i+1}}.
        // 4. To maximize the number of cells colored 'x', we want the condition in point 2 to hold for as many 'i' as possible. This means we should:
        //    a. Include the numbers {0, 1, ..., x-1} relatively early in the permutation.
        //    b. Delay including the number 'x' until the very end of the permutation.
        
        if (x == 0) {
            // Special Case: Maximize MEX = 0.
            // MEX is 0 if and only if 0 is *not* present in the prefix {p_1, ..., p_i}.
            // To keep MEX=0 for the maximum duration (i.e., for cells 1 to n-1),
            // the number 0 must appear as late as possible, i.e., at the very end.
            // The permutation [1, 2, ..., n-1, 0] achieves this.
            // - Cell 1: MEX(1) = 0
            // - Cell 2: MEX(1, 2) = 0
            // - ...
            // - Cell n-1: MEX(1, 2, ..., n-1) = 0
            // - Cell n: MEX(1, 2, ..., n-1, 0) = n
            // This results in n-1 cells being colored 0, which is the maximum possible.

            // Print numbers from 1 to n-1
            for (int i = 1; i <= n - 1; ++i) {
                std::cout << i << " "; // Print the number followed by a space
            }
            // Print 0 as the last element of the permutation
            std::cout << 0 << "\n"; // Followed by a newline for the next test case output

        } else {
            // General Case: Maximize MEX = x (where x > 0).
            // Optimal Strategy:
            // 1. Place {0, 1, ..., x-1} at the beginning. This ensures MEX reaches 'x' after x elements.
            // 2. Place 'x' at the very end. This ensures MEX remains 'x' for as long as possible.
            // 3. Fill the middle positions with all remaining numbers ({x+1, ..., n-1}) in any order.
            // The constructed permutation is: [0, 1, ..., x-1, x+1, ..., n-1, x]
            // Let's trace the colors:
            // - Cell 1: p_1=0. MEX(0) = 1.
            // - ...
            // - Cell x: p_1..p_x = [0..x-1]. MEX(0..x-1) = x. (First time color x appears)
            // - Cell x+1: p_1..p_{x+1} = [0..x-1, x+1]. MEX(...) = x.
            // - ...
            // - Cell n-1: p_1..p_{n-1} = [0..x-1, x+1..n-1]. MEX(...) = x.
            // - Cell n: p_1..p_n = [0..x-1, x+1..n-1, x]. MEX(...) = n.
            // The cells colored 'x' are cells x, x+1, ..., n-1.
            // The total count is (n-1) - x + 1 = n-x cells. This is the maximum possible.

            // Print 0 first (p_1)
            std::cout << 0 << " ";

            // Print numbers from 1 up to (but not including) x (p_2 to p_x)
            for (int i = 1; i <= x - 1; ++i) {
                std::cout << i << " "; // Print number followed by a space
            }

            // Print numbers from x+1 up to n-1 (p_{x+1} to p_{n-1})
            // These fill the middle part before the final element x
            for (int i = x + 1; i <= n - 1; ++i) {
                std::cout << i << " "; // Print number followed by a space
            }

            // Print x as the last element (p_n) *if* x is actually part of the 0..n-1 range.
            // If x == n, the target color 'n' can only be the MEX of the full permutation [0..n-1],
            // which colors cell 'n'. No cell can be colored 'n' before that.
            // The loops above already print [0, 1, ..., n-1] if x=n. We should *not* print x=n again.
            if (x < n) {
                 std::cout << x; // Print x (no trailing space needed before newline)
            }
            // Add the newline character at the end of the output line for this test case.
            // This works whether the last printed element was n-1 (if x=n) or x (if x<n).
            std::cout << "\n";
        }
    }
    return 0; // Indicate successful program execution
}