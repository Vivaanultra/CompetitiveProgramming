#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

// Define a structure to store the range of possible ratings
struct RatingRange {
    long long min_r;
    long long max_r;

    // Initialize to an impossible state (min > max)
    RatingRange() : min_r(LLONG_MAX), max_r(-1) {}
};

void solve() {
    long long r0, x, d;
    int n;
    cin >> r0 >> x >> d >> n;
    string s;
    cin >> s;

    // dp[i][j] stores the rating range [min, max]
    // after round i (1-indexed)
    // having participated in exactly j rated rounds.
    vector<vector<RatingRange>> dp(n + 1, vector<RatingRange>(n + 1));

    // Base case: After 0 rounds, 0 rated, rating is [r0, r0]
    dp[0][0].min_r = r0;
    dp[0][0].max_r = r0;

    for (int i = 1; i <= n; ++i) {
        char round_type = s[i - 1]; // Current round (1-indexed)

        for (int j = 0; j <= i; ++j) { // Target rated rounds j
            
            RatingRange combined_range;
            long long min_from_unrated = LLONG_MAX;
            long long max_from_unrated = -1;
            long long min_from_rated = LLONG_MAX;
            long long max_from_rated = -1;

            // Case 1: Round i was UNRATED
            // This means we came from state dp[i-1][j]
            if (j <= i - 1) {
                RatingRange prev = dp[i - 1][j];
                if (prev.min_r <= prev.max_r) { // If previous state is reachable
                    if (round_type == '2') {
                        // Div 2 is unrated if rating >= X
                        // We need *some* rating in [prev.min_r, prev.max_r] to be >= X
                        if (prev.max_r >= x) {
                            // The ratings that were >= X stay the same
                            // The new range is [max(prev.min_r, X), prev.max_r]
                            min_from_unrated = max(prev.min_r, x);
                            max_from_unrated = prev.max_r;
                        }
                    }
                    // Div 1 rounds are never unrated
                }
            }

            // Case 2: Round i was RATED
            // This means we came from state dp[i-1][j-1]
            if (j > 0) {
                RatingRange prev = dp[i - 1][j - 1];
                if (prev.min_r <= prev.max_r) { // If previous state is reachable
                    if (round_type == '1') {
                        // Div 1 is always rated
                        // New range is [max(0, prev.min_r - D), prev.max_r + D]
                        min_from_rated = max(0LL, prev.min_r - d);
                        max_from_rated = prev.max_r + d;
                    } else if (round_type == '2') {
                        // Div 2 is rated if rating < X
                        // We need *some* rating in [prev.min_r, prev.max_r] to be < X
                        if (prev.min_r < x) {
                            // The ratings that were < X get rated
                            // The rated range is [prev.min_r, min(prev.max_r, X - 1)]
                            // New range is [max(0, prev.min_r - D), min(prev.max_r, X - 1) + D]
                            min_from_rated = max(0LL, prev.min_r - d);
                            max_from_rated = min(prev.max_r, x - 1) + d;
                        }
                    }
                }
            }

            // Combine the ranges from the unrated and rated transitions
            // The new range is the union of the two resulting ranges
            dp[i][j].min_r = min(min_from_unrated, min_from_rated);
            dp[i][j].max_r = max(max_from_unrated, max_from_rated);
        }
    }

    // Find the maximum j (rated rounds) that is reachable after n rounds
    int max_rated_rounds = 0;
    for (int j = n; j >= 0; --j) {
        if (dp[n][j].min_r <= dp[n][j].max_r) {
            max_rated_rounds = j;
            break;
        }
    }
    cout << max_rated_rounds << endl;
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