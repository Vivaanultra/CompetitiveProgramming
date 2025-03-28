// This problem should be rated 1000-1200 on Codeforces because it requires
// understanding of string manipulation and basic data structures (map),
// but the solution is straightforward once you understand the concept of trace
#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    // Read the number of test cases we need to process
    int testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; i++) {
        // Read the length of the string we want to create
        int length;
        cin >> length;
        // Create an array called 'trace' where each number tells us
        // how many times we've seen a character before.
        // For example, if trace[3] = 2, it means the character at position 3
        // has appeared exactly 2 times before this position
        vector<int> trace(length);
        for (int j = 0; j < length; j++) {
            cin >> trace[j];
        }
        
        // This will store our final answer - the string we're building
        string result;
        // Keep count of how many times we've used each letter (a to z)
        vector<int> freq(26, 0);
        // Keep track of which letters (a to z) we've used at least once
        vector<bool> used(26, false);
        
        // Go through each position in our string one by one
        for (int j = 0; j < length; j++) {
            // If we need a character that hasn't appeared before (trace[j] = 0)
            if (trace[j] == 0) {
                // Look for the first letter in the alphabet we haven't used yet
                for (int c = 0; c < 26; c++) {
                    if (!used[c]) {
                        // Add this new letter to our string
                        result += (char)('a' + c);
                        // Mark it as used and increase its frequency count
                        used[c] = true;
                        freq[c]++;
                        break;
                    }
                }
            } else {
                // If we need a character that has appeared before,
                // find a letter that we've used exactly trace[j] times
                for (int c = 0; c < 26; c++) {
                    if (used[c] && freq[c] == trace[j]) {
                        // Add this letter to our string and increase its count
                        result += (char)('a' + c);
                        freq[c]++;
                        break;
                    }
                }
            }
        }
        
        // Print the resulting string with a newline
        cout << result << "\n";
    }
    return 0;
}