#include <bits/stdc++.h>

using namespace std;

// This function calculates the number of turns needed to reduce a grid
// of size r x c to 1 x 1, assuming Fouad always plays optimally
// by recentering the monster after each of Mouf's cuts.
long long calculate_sub_turns(long long r, long long c) {
    long long turns = 0;
    // Calculate turns to reduce the number of rows to 1.
    // In each step, the dimension is halved (ceiling).
    while (r > 1) {
        r = (r + 1) / 2; // This is equivalent to ceil(r / 2.0)
        turns++;
    }
    // Calculate turns to reduce the number of columns to 1.
    while (c > 1) {
        c = (c + 1) / 2;
        turns++;
    }
    return turns;
}

void solve() {
    long long n, m, a, b;
    cin >> n >> m >> a >> b;

    // Mouf considers his four possible initial cuts.
    // For each, he calculates the total turns: 1 (for the first cut)
    // plus the number of turns Fouad can force afterwards.

    // Option 1: Keep the top 'a' rows.
    long long turns1 = 1 + calculate_sub_turns(a, m);

    // Option 2: Keep the bottom 'n - a + 1' rows.
    long long turns2 = 1 + calculate_sub_turns(n - a + 1, m);

    // Option 3: Keep the left 'b' columns.
    long long turns3 = 1 + calculate_sub_turns(n, b);

    // Option 4: Keep the right 'm - b + 1' columns.
    long long turns4 = 1 + calculate_sub_turns(n, m - b + 1);

    // Mouf plays optimally, so he chooses the cut that leads to the minimum total turns.
    cout << min({turns1, turns2, turns3, turns4}) << endl;
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}