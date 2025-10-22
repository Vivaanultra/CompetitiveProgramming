#include <bits/stdc++.h>

using namespace std;

// Function to solve a single test case
void solve() {
    int n;
    cin >> n;

    // Step 1: Count frequencies of each number in the input array.
    // We only care about numbers from 0 to n.
    vector<int> counts(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x <= n) {
            counts[x]++;
        }
    }

    // Step 2: Use a difference array to mark the ranges of 'k' for each possible MEX 'm'.
    // ans_diff[k] will store the change in the number of possible MEX values at k.
    vector<long long> ans_diff(n + 2, 0);

    // This flag checks if all numbers {0, 1, ..., m-1} exist in the original array.
    bool prereq_ok = true;

    for (int m = 0; m <= n; ++m) {
        // Check the prerequisite for 'm'.
        if (m > 0 && counts[m - 1] == 0) {
            prereq_ok = false;
        }

        // If the prerequisite fails for 'm', it also fails for all m' > m.
        if (!prereq_ok) {
            break;
        }

        // Determine the range of removals [k_min, k_max] for which MEX=m is possible.
        long long k_min = counts[m]; // Must remove all 'm's.
        long long k_max = n - m;     // Must keep at least m elements {0..m-1}.

        if (k_min <= k_max) {
            // Mark the contribution of 'm' in the difference array.
            ans_diff[k_min]++;
            ans_diff[k_max + 1]--;
        }
    }

    // Step 3: Compute the prefix sums of the difference array to get the final answers.
    long long current_count = 0;
    for (int k = 0; k <= n; ++k) {
        current_count += ans_diff[k];
        cout << current_count << (k == n ? "" : " ");
    }
    cout << "\n";
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