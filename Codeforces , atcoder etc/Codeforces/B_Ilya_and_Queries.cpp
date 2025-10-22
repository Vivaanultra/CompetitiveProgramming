#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int m;
    cin >> m;
    int n = s.length();

    vector<int> prefix_counts(n, 0);
    for (int i = 1; i < n; ++i) {
        prefix_counts[i] = prefix_counts[i - 1];
        if (s[i] == s[i - 1]) {
            prefix_counts[i]++;
        }
    }

    for (int k = 0; k < m; ++k) {
        int l, r;
        cin >> l >> r;
        // Adjust for 0-based indexing and the query range
        int result = prefix_counts[r - 1] - prefix_counts[l - 1];
        cout << result << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // This problem format has the string first, then all queries.
    // So we don't need a `t` loop for test cases.
    solve();

    return 0;
}