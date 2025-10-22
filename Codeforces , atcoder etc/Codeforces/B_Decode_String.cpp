#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// This function solves a single test case
void solve() {
    int n;
    std::cin >> n;
    std::string t;
    std::cin >> t;

    std::string s = "";
    int i = n - 1;

    // Iterate through the encoded string from right to left
    while (i >= 0) {
        if (t[i] == '0') {
            // If the character is '0', it's a two-digit number
            // The number is formed by the two preceding digits
            int num = std::stoi(t.substr(i - 2, 2));
            // Convert the number back to a character ('a' is 1, 'b' is 2, etc.)
            s += (char)('a' + num - 1);
            // Move the pointer past the three characters used ('d' 'd' '0')
            i -= 3;
        } else {
            // If the character is not '0', it's a single-digit number
            int num = t[i] - '0';
            // Convert the number back to a character
            s += (char)('a' + num - 1);
            // Move the pointer past the single character used
            i -= 1;
        }
    }

    // The resulting string is built backwards, so we need to reverse it
    std::reverse(s.begin(), s.end());
    std::cout << s << std::endl;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int q;
    std::cin >> q;
    while (q--) {
        solve();
    }

    return 0;
}