#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long m;
    if (!(cin >> n >> m)) return;

    // Store character counts for each street and total counts
    vector<array<int, 26>> street_counts(n, {0});
    array<long long, 26> total_counts = {0};

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (char c : s) {
            int char_idx = c - 'A';
            street_counts[i][char_idx]++;
            total_counts[char_idx]++;
        }
    }

    for (int i = 0; i < n; ++i) {
        long long max_sets_needed = 0;
        bool possible = true;

        for (int c = 0; c < 26; ++c) {
            long long needed_for_current = street_counts[i][c];
            long long provided_by_others = total_counts[c] - street_counts[i][c];

            if (provided_by_others == 0) {
                // If others provide 0, we can't have any need > 0
                if (needed_for_current > 0) {
                    possible = false;
                    break;
                }
            } else {
                // Calculate ceil(needed / provided)
                // Formula: (numerator + denominator - 1) / denominator
                long long sets = (needed_for_current + provided_by_others - 1) / provided_by_others;
                if (sets > max_sets_needed) {
                    max_sets_needed = sets;
                }
            }
        }

        if (!possible || max_sets_needed > m) {
            cout << -1 << (i == n - 1 ? "" : " ");
        } else {
            cout << (m - max_sets_needed) << (i == n - 1 ? "" : " ");
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}