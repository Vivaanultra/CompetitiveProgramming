// Use competitive programming practices as requested
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();

    // The start and end characters determine the path properties
    char start_char = s[0];
    char end_char = s[n - 1];

    // 1. Calculate the minimum cost. This is simply the difference
    // in alphabet values between the start and end.
    long long cost = abs(start_char - end_char);

    // 2. Collect all valid intermediate tiles.
    // A tile is valid if its character value is between the start and end values.
    // We store a pair: {character, original 1-based index}.
    vector<pair<char, int>> intermediate_tiles;
    for (int i = 1; i < n - 1; ++i) {
        // Check if s[i] is between start_char and end_char (inclusive)
        if ((s[i] >= start_char && s[i] <= end_char) || (s[i] <= start_char && s[i] >= end_char)) {
            intermediate_tiles.push_back({s[i], i + 1});
        }
    }

    // 3. Sort the intermediate tiles to ensure the path is monotonic.
    // This guarantees the minimum cost.
    if (start_char < end_char) {
        // If we're moving "up" the alphabet, sort ascendingly by char value.
        sort(intermediate_tiles.begin(), intermediate_tiles.end());
    } else {
        // If we're moving "down" the alphabet, sort descendingly.
        // Sorting by reverse iterators is a clean way to do this.
        sort(intermediate_tiles.rbegin(), intermediate_tiles.rend());
    }

    // 4. Print the results.
    // The total number of tiles is 2 (start and end) + all intermediates.
    cout << cost << " " << intermediate_tiles.size() + 2 << endl;

    // Print the path sequence: start, sorted intermediates, end.
    cout << 1 << " ";
    for (const auto& p : intermediate_tiles) {
        cout << p.second << " ";
    }
    cout << n << endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}