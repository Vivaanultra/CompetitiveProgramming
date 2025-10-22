#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// Using competitive programming practices as requested
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;

    long long total_cost = 0;
    vector<long long> remainders;
    remainders.reserve(n); // Pre-allocate memory for efficiency

    // 1. Simplify the problem
    for (int i = 0; i < n; ++i) {
        long long current_weight;
        cin >> current_weight;
        // Add the fixed part of the cost that doesn't depend on pairing
        total_cost += current_weight / k;
        // Store the remainder for the pairing subproblem
        remainders.push_back(current_weight % k);
    }

    // 2. Organize the data for the greedy strategy
    sort(remainders.begin(), remainders.end());

    // 3. Pair greedily using two pointers
    int left = 0;
    int right = n - 1;

    while (left < right) {
        // Try to pair the smallest available remainder with the largest
        if (remainders[left] + remainders[right] >= k) {
            // Success! This pair gives a bonus +1 to the cost.
            total_cost++;
            // Both items are now used in a successful pair.
            left++;
            right--;
        } else {
            // The smallest item is too small to form a sum >= k even with the largest.
            // Therefore, it can't form a successful pair with any available item.
            // It will be paired with another "losing" item, contributing 0 bonus.
            // We discard it from consideration for forming a successful pair.
            left++;
        }
    }

    cout << total_cost << endl;
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