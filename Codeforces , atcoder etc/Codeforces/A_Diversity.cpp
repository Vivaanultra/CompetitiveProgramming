#include <bits/stdc++.h> // Includes everything

using namespace std; // Common in CP, use with caution elsewhere

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // Fast I/O

    string s;
    cin >> s;
    int k;
    cin >> k;

    if (k > s.length()) {
        cout << "impossible\n";
        return 0;
    }

    // Option 1: Using a boolean array (often slightly faster for fixed small alphabet)
    bool present[26] = {false};
    int distinct_count = 0;
    for (char c : s) {
        if (!present[c - 'a']) {
            present[c - 'a'] = true;
            distinct_count++;
        }
    }

    /*
    // Option 2: Using std::set (more idiomatic STL, might be slightly slower)
    // set<char> distinct_chars;
    // for (char c : s) {
    //     distinct_chars.insert(c);
    // }
    // int distinct_count = distinct_chars.size();
    */
    
    /*
    // Option 3: Even more concise with std::set constructor (if you only need the count once)
    // set<char> distinct_chars(s.begin(), s.end());
    // int distinct_count = distinct_chars.size();
    */


    if (distinct_count >= k) {
        cout << 0 << "\n";
    } else {
        cout << k - distinct_count << "\n";
    }

    return 0;
}