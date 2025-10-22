#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Counts subarrays summing to 's' where all elements satisfy a given predicate.
 * * This O(N) average time solution uses an unordered_map for O(1) prefix sum lookups.
 * @param n The size of the array.
 * @param a The input array.
 * @param s The target sum.
 * @param predicate A function that returns true if an element is valid for the segment.
 * @return The total count of such subarrays.
 */
long long count_subarrays_with_predicate(
    int n,
    const vector<int>& a,
    long long s,
    const function<bool(int)>& predicate) 
{
    long long total_count = 0;
    // Using unordered_map for O(1) average time complexity for lookups/insertions.
    unordered_map<long long, int> prefix_sum_counts;
    prefix_sum_counts[0] = 1;
    long long current_sum = 0;

    for (int i = 0; i < n; ++i) {
        if (!predicate(a[i])) {
            // Reset for a new segment.
            prefix_sum_counts.clear();
            prefix_sum_counts[0] = 1;
            current_sum = 0;
            continue;
        }

        current_sum += a[i];
        
        // O(1) average lookup.
        if (prefix_sum_counts.count(current_sum - s)) {
            total_count += prefix_sum_counts[current_sum - s];
        }
        
        // O(1) average insertion.
        prefix_sum_counts[current_sum]++;
    }
    return total_count;
}

void solve() {
    int n;
    long long s;
    int x;
    cin >> n >> s >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // 1. Count subarrays where all elements are <= x and sum is s.
    auto max_le_x = [&](int val) { return val <= x; };
    long long count1 = count_subarrays_with_predicate(n, a, s, max_le_x);

    // 2. Count subarrays where all elements are < x and sum is s.
    auto max_lt_x = [&](int val) { return val < x; };
    long long count2 = count_subarrays_with_predicate(n, a, s, max_lt_x);

    cout << count1 - count2 << endl;
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