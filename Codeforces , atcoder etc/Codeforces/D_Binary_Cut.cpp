#include <bits/stdc++.h>

using namespace std;

// Function to calculate number of contiguous blocks in a string
// e.g., "11001" -> 3 blocks
int count_blocks(const string& str) {
    if (str.empty()) return 0;
    int blocks = 1;
    for (size_t i = 1; i < str.size(); ++i) {
        if (str[i] != str[i - 1]) {
            blocks++;
        }
    }
    return blocks;
}

void solve() {
    string s;
    cin >> s;
    int n = s.length();

    // Precompute block counts for prefixes
    // pre[i] stores the number of blocks in s[0...i-1]
    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1];
        if (i == 1 || s[i - 1] != s[i - 2]) {
            pre[i]++;
        }
    }

    // Precompute block counts for suffixes
    // suf[i] stores the number of blocks in s[i...n-1]
    vector<int> suf(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        suf[i] = suf[i + 1];
        if (i == n - 1 || s[i] != s[i + 1]) {
            suf[i]++;
        }
    }

    int min_pieces = n; // Initialize with max possible pieces

    // Case 1: No mixed piece (split point k). M is empty.
    // We just cut prefix and suffix into pure components.
    for (int k = 0; k <= n; ++k) {
        min_pieces = min(min_pieces, pre[k] + suf[k]);
    }

    // Case 2: One mixed piece M = s[i...j]
    for (int i = 0; i < n; ++i) {
        bool seen_one = false;
        bool possible = true;
        for (int j = i; j < n; ++j) {
            // Check if s[i...j] is sorted incrementally
            if (s[j] == '1') seen_one = true;
            if (s[j] == '0' && seen_one) possible = false;

            if (!possible) break; // Not sorted anymore

            // Cost = blocks in prefix + 1 (the mixed piece M) + blocks in suffix
            int current_pieces = pre[i] + 1 + suf[j + 1];
            min_pieces = min(min_pieces, current_pieces);
        }
    }

    cout << min_pieces << endl;
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