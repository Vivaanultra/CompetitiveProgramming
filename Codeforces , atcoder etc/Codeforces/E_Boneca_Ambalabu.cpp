#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Step 1: Preprocessing to count set bits for each position
    vector<int> bit_counts(30, 0);
    for (int num : a) {
        for (int j = 0; j < 30; ++j) {
            if ((num >> j) & 1) {
                bit_counts[j]++;
            }
        }
    }

    long long max_total_sum = 0;

    // Step 2 & 3: Iterate through each number a[k] and calculate its sum
    for (int k : a) {
        long long current_total_sum = 0;
        for (int j = 0; j < 30; ++j) {
            long long power_of_2 = (1LL << j);
            int count1 = bit_counts[j];
            int count0 = n - count1;

            // Check the j-th bit of the current number k
            if ((k >> j) & 1) {
                // If bit is 1, it mismatches with the count0 numbers that have a 0
                current_total_sum += (long long)count0 * power_of_2;
            } else {
                // If bit is 0, it mismatches with the count1 numbers that have a 1
                current_total_sum += (long long)count1 * power_of_2;
            }
        }
        // Step 4: Keep track of the maximum sum found
        if (current_total_sum > max_total_sum) {
            max_total_sum = current_total_sum;
        }
    }

    cout << max_total_sum << "\n";
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