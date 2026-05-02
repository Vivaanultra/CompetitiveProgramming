#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long Ax, Ay, Bx, By;
    cin >> n >> Ax >> Ay >> Bx >> By;

    vector<long long> X(n), Y(n);
    for (int i = 0; i < n; i++) cin >> X[i];
    for (int i = 0; i < n; i++) cin >> Y[i];

    // Group houses by x-coordinate.
    // map<x, pair<min_y, max_y>>
    map<long long, pair<long long, long long>> columns;
    for (int i = 0; i < n; i++) {
        long long x = X[i];
        long long y = Y[i];
        if (columns.find(x) == columns.end()) {
            columns[x] = {y, y};
        } else {
            columns[x].first = min(columns[x].first, y);
            columns[x].second = max(columns[x].second, y);
        }
    }

    // DP State
    // dp_low: min cost to finish the current column and end at min_y
    // dp_high: min cost to finish the current column and end at max_y
    
    // Initial state: We start at (Ax, Ay). 
    // It's like having a previous column at Ax with min_y = max_y = Ay.
    long long prev_x = Ax;
    long long prev_low_y = Ay;
    long long prev_high_y = Ay;
    long long dp_low = 0;
    long long dp_high = 0;

    for (auto const& [curr_x, range] : columns) {
        long long curr_low = range.first;
        long long curr_high = range.second;
        long long dx = curr_x - prev_x;
        long long span = curr_high - curr_low; // Cost to traverse the column itself

        // Calculate cost to reach the CURRENT Low point (ending at bottom)
        // Option 1: Came from Prev Low -> went to Curr High -> down to Curr Low
        long long from_low_to_low = dp_low + dx + abs(curr_high - prev_low_y) + span;
        // Option 2: Came from Prev High -> went to Curr High -> down to Curr Low
        long long from_high_to_low = dp_high + dx + abs(curr_high - prev_high_y) + span;
        
        long long next_dp_low = min(from_low_to_low, from_high_to_low);

        // Calculate cost to reach the CURRENT High point (ending at top)
        // Option 1: Came from Prev Low -> went to Curr Low -> up to Curr High
        long long from_low_to_high = dp_low + dx + abs(curr_low - prev_low_y) + span;
        // Option 2: Came from Prev High -> went to Curr Low -> up to Curr High
        long long from_high_to_high = dp_high + dx + abs(curr_low - prev_high_y) + span;

        long long next_dp_high = min(from_low_to_high, from_high_to_high);

        // Update state
        dp_low = next_dp_low;
        dp_high = next_dp_high;
        prev_x = curr_x;
        prev_low_y = curr_low;
        prev_high_y = curr_high;
    }

    // Final step: Move from the last column to (Bx, By)
    long long final_dx = Bx - prev_x;
    long long ans_from_low = dp_low + final_dx + abs(By - prev_low_y);
    long long ans_from_high = dp_high + final_dx + abs(By - prev_high_y);

    cout << min(ans_from_low, ans_from_high) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}