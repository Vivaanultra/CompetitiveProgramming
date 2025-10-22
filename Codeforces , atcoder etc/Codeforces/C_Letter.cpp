#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

// bits/stdc++.h is generally used in competitive programming for convenience,
// but including specific headers is better practice in production code.

using namespace std;

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.length();

    // 1. Calculate the total number of uppercase letters in the string.
    int total_upper = 0;
    for (char c : s) {
        if (isupper(c)) {
            total_upper++;
        }
    }

    // Initialize min_changes with the cost of making the entire string lowercase.
    // This corresponds to a split point at the beginning (i=0).
    int min_changes = total_upper;

    int lower_in_prefix = 0;
    int upper_in_prefix = 0;

    // 2. Iterate through all possible split points.
    // The loop variable 'i' represents the end of the prefix.
    for (int i = 0; i < n; ++i) {
        // Update counts for the prefix ending at index 'i'.
        if (islower(s[i])) {
            lower_in_prefix++;
        } else {
            upper_in_prefix++;
        }

        // 3. Calculate the cost for the current split point (i+1).
        // Cost = (lowercase to change in prefix) + (uppercase to change in suffix).
        // Uppercase in suffix = total_upper - upper_in_prefix.
        int current_changes = lower_in_prefix + (total_upper - upper_in_prefix);

        // 4. Update the minimum changes found so far.
        min_changes = min(min_changes, current_changes);
    }

    cout << min_changes << endl;

    return 0;
}