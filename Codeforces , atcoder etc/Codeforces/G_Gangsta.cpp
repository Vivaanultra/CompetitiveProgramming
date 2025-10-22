#include <bits/stdc++.h>

using namespace std;

// Using global arrays for BITs for performance in competitive programming
const int MAXN = 400005; // Max BIT size: 2*n_max + 5
long long bit_count[MAXN];
long long bit_sum[MAXN];
int N_BIT; // To store the actual size needed for the current test case

// Updates a value in the Fenwick tree
void update(long long bit[], int idx, long long delta) {
    for (; idx <= N_BIT; idx += idx & -idx) {
        bit[idx] += delta;
    }
}

// Queries the prefix sum in the Fenwick tree
long long query(long long bit[], int idx) {
    long long sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += bit[idx];
    }
    return sum;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // Part 1: Sum of lengths of all substrings
    long long sum_len = (long long)n * (n + 1) * (n + 2) / 6;

    // Part 2: Sum of absolute differences of (ones - zeros)
    // Create a prefix sum array `p` based on the difference
    vector<int> p(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        p[i + 1] = p[i] + (s[i] == '1' ? 1 : -1);
    }

    // Initialize Fenwick Trees
    // The values in p range from -n to n. We offset them to get non-negative indices.
    int offset = n;
    N_BIT = 2 * n + 1;
    for (int i = 0; i <= N_BIT; ++i) {
        bit_count[i] = 0;
        bit_sum[i] = 0;
    }

    long long total_abs_diff_sum = 0;

    for (int j = 0; j <= n; ++j) {
        long long val = p[j];
        int idx = val + offset + 1; // BIT is 1-indexed

        // Contribution from pairs (p[i], p[j]) where p[i] < p[j]
        long long count_less = query(bit_count, idx - 1);
        long long sum_less = query(bit_sum, idx - 1);
        total_abs_diff_sum += val * count_less - sum_less;

        // Contribution from pairs (p[i], p[j]) where p[i] >= p[j]
        long long count_total = j; // we have seen j elements (from p[0] to p[j-1])
        long long sum_total = query(bit_sum, N_BIT);
        long long count_ge = count_total - count_less;
        long long sum_ge = sum_total - sum_less;
        total_abs_diff_sum += sum_ge - val * count_ge;

        // Add p[j] to the BITs for subsequent calculations
        update(bit_count, idx, 1);
        update(bit_sum, idx, val);
    }

    // The final answer is the average of the two sums.
    long long final_ans = (sum_len + total_abs_diff_sum) / 2;
    cout << final_ans << endl;
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