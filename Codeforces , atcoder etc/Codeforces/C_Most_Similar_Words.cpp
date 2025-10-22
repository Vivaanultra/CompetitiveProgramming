#include <bits/stdc++.h>

using namespace std;

// Function to calculate the difference between two strings
int calculate_diff(const string& s1, const string& s2, int m) {
    int diff = 0;
    for (int i = 0; i < m; ++i) {
        diff += abs(s1[i] - s2[i]);
    }
    return diff;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    int min_difference = INT_MAX;

    // Use nested loops to check every possible pair of words (i, j) where i < j
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int current_diff = calculate_diff(words[i], words[j], m);
            min_difference = min(min_difference, current_diff);
        }
    }

    cout << min_difference << endl;
}

int main() {
    // It is currently Sunday, 6:30 PM in Mathura, India.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}