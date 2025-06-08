#include <bits/stdc++.h> // Includes most standard libraries

using namespace std; // Using standard namespace as per preference

int main() {
    // Optional: For faster I/O in competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, s; // m: length, s: sum of digits
    cin >> m >> s;

    // --- Edge Case Handling ---

    // Case 1: Sum is 0
    if (s == 0) {
        if (m == 1) {
            // Only possible number is "0" if length is 1 and sum is 0
            cout << "0 0" << endl;
        } else {
            // If length > 1 and sum is 0, no such number exists (e.g., "00" has leading zero)
            cout << "-1 -1" << endl;
        }
        return 0; // Exit after handling this case
    }

    // Case 2: Sum is impossible for the given length
    // (s > 0 at this point)
    // If sum s is greater than the maximum possible sum (m * 9)
    // or if s is less than 1 (which is actually covered since s > 0 here, but good for logical completeness if s could be <0)
    // The problem constraints state s >= 0, and we handled s=0 above. So s >= 1 here.
    // Thus, s < 1 is not possible here. The main check is s > 9*m.
    if (s > 9 * m) {
        cout << "-1 -1" << endl;
        return 0; // Exit after handling this case
    }

    // If we reach here, a solution exists: m >= 1, s >= 1, and s <= 9*m.

    // --- Constructing the Smallest Number ---
    string min_num_str(m, ' '); // Initialize string for the smallest number
    int s_for_min = s;          // Temporary sum for minimum number construction

    for (int i = 0; i < m; ++i) { // Iterate through each digit position
        // Determine the smallest possible digit for the current position 'i'
        // For the first digit (i=0), it must be at least 1 (since s > 0 here).
        // For other digits (i > 0), it can be 0.
        int start_d_candidate = (i == 0) ? 1 : 0;

        for (int d_candidate = start_d_candidate; d_candidate <= 9; ++d_candidate) {
            // Check if placing 'd_candidate' here is valid:
            // 1. We can afford this digit: s_for_min - d_candidate >= 0
            // 2. The remaining sum (s_for_min - d_candidate) can be formed by
            //    the remaining digits (m - 1 - i).
            //    Min sum for remaining digits is 0. Max sum is 9 * (m - 1 - i).
            int remaining_len = m - 1 - i;
            if ((s_for_min - d_candidate >= 0) &&
                (s_for_min - d_candidate <= 9 * remaining_len)) {
                min_num_str[i] = (char)(d_candidate + '0'); // Place the digit
                s_for_min -= d_candidate;                   // Update the remaining sum
                break; // Found the smallest valid digit for this position, move to next
            }
        }
    }

    // --- Constructing the Largest Number ---
    string max_num_str(m, ' '); // Initialize string for the largest number
    int s_for_max = s;          // Temporary sum for maximum number construction

    for (int i = 0; i < m; ++i) { // Iterate through each digit position
        // For the largest number, greedily pick the largest possible digit
        // The largest digit we can place is min(9, current_remaining_sum)
        int digit_to_place = min(9, s_for_max);
        max_num_str[i] = (char)(digit_to_place + '0'); // Place the digit
        s_for_max -= digit_to_place;                   // Update the remaining sum
    }

    // Output the results
    cout << min_num_str << " " << max_num_str << endl;

    return 0;
}