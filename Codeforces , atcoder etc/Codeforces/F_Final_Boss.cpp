#include <iostream>
#include <vector>
#include <numeric>

// Using competitive programming practices
#include <bits/stdc++.h>
using namespace std;

// This function checks if it's possible to win within a given number of turns.
bool can_win(long long turns, long long h, int n, const vector<long long>& a, const vector<long long>& c) {
    long long total_damage = 0;
    for (int i = 0; i < n; ++i) {
        // Calculate how many times attack 'i' can be used within the given turns
        long long num_uses = (turns - 1) / c[i] + 1;
        total_damage += a[i] * num_uses;

        // Optimization: if damage is already enough, no need to calculate further
        if (total_damage >= h) {
            return true;
        }
    }
    return total_damage >= h;
}

void solve() {
    long long h;
    int n;
    cin >> h >> n;
    vector<long long> a(n), c(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> c[i];

    // Binary search for the minimum number of turns
    long long low = 1;
    // A safe upper bound for the number of turns
    long long high = 40000000000LL; 
    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (can_win(mid, h, n, a, c)) {
            // If we can win in 'mid' turns, it might be the answer.
            // Let's try for an even smaller number of turns.
            ans = mid;
            high = mid - 1;
        } else {
            // If we can't win, we need more turns.
            low = mid + 1;
        }
    }

    cout << ans << endl;
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