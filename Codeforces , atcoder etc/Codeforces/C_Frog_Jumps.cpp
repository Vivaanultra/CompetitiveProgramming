#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // For std::max

// It's a common competitive programming practice to use bits/stdc++.h
// but including specific headers is generally better for clarity and compile times.
// #include <bits/stdc++.h>

// Using namespace std is also common in competitive programming for brevity.
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t;
    while (t--) {
        string s; // The string of 'L' and 'R'
        cin >> s;
        int n = s.length();

        int max_jump_needed = 0;
        int last_r_cell_position = 0; // Start at cell 0

        // Iterate through the characters of the string, representing cells 1 to n
        for (int i = 0; i < n; ++i) {
            // s[i] is the character for cell i+1
            if (s[i] == 'R') {
                // Calculate the jump distance from the last 'R' (or cell 0) to this 'R'
                int current_cell = i + 1;
                int jump_distance = current_cell - last_r_cell_position;
                max_jump_needed = max(max_jump_needed, jump_distance);
                // Update the position of the last 'R' cell encountered
                last_r_cell_position = current_cell;
            }
        }

        // After iterating through the string, calculate the final jump
        // from the last 'R' cell (or cell 0 if no 'R's) to cell n+1.
        int final_jump_distance = (n + 1) - last_r_cell_position;
        max_jump_needed = max(max_jump_needed, final_jump_distance);

        cout << max_jump_needed << endl;
    }
    return 0;
}