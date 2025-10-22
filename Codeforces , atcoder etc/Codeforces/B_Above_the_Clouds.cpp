#include <iostream>
#include <string>
#include <vector>
#include <numeric>

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    // The logic is that a solution exists if and only if we can find a character s[i]
    // where 1 <= i <= n-2, which also appears somewhere else in the string.
    // This 'somewhere else' could be in the prefix s[0...i-1] or the suffix s[i+1...n-1].

    // Pass 1: Check for duplicates in the prefix for each character.
    std::vector<bool> prefix_match(n, false);
    std::vector<bool> seen_prefix(26, false);
    for (int i = 0; i < n; ++i) {
        if (seen_prefix[s[i] - 'a']) {
            prefix_match[i] = true;
        }
        seen_prefix[s[i] - 'a'] = true;
    }

    // Pass 2: Check for duplicates in the suffix for each character.
    std::vector<bool> suffix_match(n, false);
    std::vector<bool> seen_suffix(26, false);
    for (int i = n - 1; i >= 0; --i) {
        if (seen_suffix[s[i] - 'a']) {
            suffix_match[i] = true;
        }
        seen_suffix[s[i] - 'a'] = true;
    }

    // Check the condition for the middle part of the string
    bool possible = false;
    for (int i = 1; i < n - 1; ++i) {
        // If s[i] has a match in its prefix or its suffix, we can form a valid a, b, c.
        if (prefix_match[i] || suffix_match[i]) {
            possible = true;
            break;
        }
    }

    if (possible) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}