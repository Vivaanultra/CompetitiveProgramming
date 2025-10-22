#include <bits/stdc++.h>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // Strengths are between 1 and 1000, so a simple array works as a frequency map.
    vector<int> counts(1001, 0);
    for (int i = 0; i < n; ++i) {
        int strength;
        cin >> strength;
        counts[strength]++;
    }

    long long total_revenue = 0;
    long long prefix_sum = 0; // Stores the sum of strengths of all teams processed so far.
    long long teams_seen = 0; // Stores the count of teams processed so far.

    // Iterate through the strengths in increasing order (from 1 to 1000).
    for (int s = 1; s <= 1000; ++s) {
        // If there are teams with the current strength 's'
        if (counts[s] > 0) {
            // Each of the 'counts[s]' teams with strength 's' will play against
            // all 'teams_seen' teams that have a smaller strength.
            // The revenue for one team of strength 's' against all previous teams is:
            // (s - s_1) + (s - s_2) + ... = (teams_seen * s) - (s_1 + s_2 + ...)
            // The term (s_1 + s_2 + ...) is the prefix_sum we've been tracking.
            total_revenue += (long long)counts[s] * (teams_seen * s - prefix_sum);

            // After calculating revenue, add the current group of teams to our totals
            // for the next iteration.
            prefix_sum += (long long)counts[s] * s;
            teams_seen += counts[s];
        }
    }

    cout << total_revenue << "\n";

    return 0;
}