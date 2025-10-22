#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    // Use a map to store the frequency of each color (digit)
    map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    // Find the frequency of the most common color
    int max_freq = 0;
    for (auto const& [key, val] : freq) {
        if (val > max_freq) {
            max_freq = val;
        }
    }

    // Apply the logic based on the max frequency
    if (max_freq == 4) {
        cout << -1 << endl;
    } else if (max_freq == 3) {
        cout << 6 << endl;
    } else if (max_freq == 2) {
        cout << 4 << endl;
    } else { // max_freq == 1
        cout << 4 << endl;
    }
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