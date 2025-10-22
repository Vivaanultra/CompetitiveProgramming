#include <bits/stdc++.h>

using namespace std;

void solve() {
    string keyboard_layout;
    cin >> keyboard_layout;
    string word;
    cin >> word;

    // Step 1: Create the keyboard map
    int positions[26];
    for (int i = 0; i < 26; ++i) {
        // keyboard_layout[i] is the character, e.g., 'q'
        // keyboard_layout[i] - 'a' is its 0-based index (e.g., 'q'-'a' = 16)
        // i + 1 is its 1-based position on the keyboard
        positions[keyboard_layout[i] - 'a'] = i + 1;
    }

    // Step 2: Simulate typing and calculate time
    long long total_time = 0;
    // Start from the second letter of the word
    for (int i = 1; i < word.length(); ++i) {
        int pos_current = positions[word[i] - 'a'];
        int pos_previous = positions[word[i - 1] - 'a'];
        total_time += abs(pos_current - pos_previous);
    }

    cout << total_time << endl;
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