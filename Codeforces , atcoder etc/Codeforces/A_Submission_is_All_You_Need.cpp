#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, int> counts;
    long long baseline_sum = 0;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        counts[val]++;
        if (val != 0) {
            baseline_sum += val;
        }
    }

    // This is the score for Strategy 1: "All Sum"
    long long max_score = baseline_sum + counts[0];

    // Now, check Strategy 2 for every possible mex target `i`
    for (int i = 1; i <= n + 1; ++i) {
        // Check if we can form the set {0, 1, ..., i-1}
        bool possible = true;
        for (int j = 0; j < i; ++j) {
            if (counts[j] == 0) {
                possible = false;
                break;
            }
        }

        if (possible) {
            // If we can form it, calculate the score
            long long current_score = i; // Score from the mex({0,...,i-1}) set
            
            // Add score from leftovers
            current_score += (counts[0] - 1); // Leftover zeros
            for (int j = 1; j < i; ++j) {
                current_score += (long long)(counts[j] - 1) * j;
            }
            for (int j = i; j <= n; ++j) {
                current_score += (long long)counts[j] * j;
            }
            
            max_score = max(max_score, current_score);
        } else {
            // If we can't form the set for mex `i`, we can't form it for `i+1` either.
            break;
        }
    }

    cout << max_score << endl;
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