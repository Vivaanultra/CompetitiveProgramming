#include <bits/stdc++.h>

using namespace std;

string n_str;
int k;
string result;

// Recursive function to build the beautiful number
// index: The current digit position we're trying to fill
// tight: A boolean flag. True if our prefix matches n, meaning we're restricted.
//        False if our prefix is already bigger, meaning we can use any digit.
// used_mask: A bitmask representing the set of digits used so far.
bool generate(int index, bool tight, int used_mask) {
    // Base case: We've successfully built a full-length number.
    if (index == n_str.length()) {
        return true;
    }

    // Determine the smallest digit we can start trying from.
    int start_digit = tight ? (n_str[index] - '0') : 0;
    
    for (int d = start_digit; d <= 9; ++d) {
        int next_mask = used_mask | (1 << d);
        
        // Check if using digit 'd' is valid
        if (__builtin_popcount(next_mask) <= k) {
            result += to_string(d);
            
            // If we choose a digit larger than n's digit, the constraint is no longer "tight".
            bool next_tight = tight && (d == start_digit);

            if (generate(index + 1, next_tight, next_mask)) {
                return true; // Found a solution
            }

            result.pop_back(); // Backtrack if this path didn't lead to a solution
        }
    }
    
    return false; // No valid digit found from this state
}


void solve() {
    long long n_val;
    cin >> n_val >> k;
    n_str = to_string(n_val);
    result = "";

    // This handles the case where we need to backtrack all the way and add a digit
    // e.g., n=98, k=1 -> answer is 111.
    while (!generate(0, true, 0)) {
        // If generate fails, it means no beautiful number with this many digits
        // is >= n. So we need a longer number.
        // The smallest beautiful number with n+1 digits is the answer.
        n_str = '1' + string(n_str.length(), '0');
        k = max(k, 1); // Ensure k is at least 1 for the next number
    }
    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}