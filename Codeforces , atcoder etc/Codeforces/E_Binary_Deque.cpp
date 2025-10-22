#include <bits/stdc++.h>
using namespace std;

// This function solves a single test case.
void solve() {
    int n;
    long long s;
    cin >> n >> s;
    vector<int> a(n);
    long long total_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_sum += a[i];
    }

    // If the total sum of ones in the array is less than s,
    // it's impossible to obtain the required sum.
    if (total_sum < s) {
        cout << -1 << "\n";
        return;
    }

    // If the total sum is already equal to s, no operations are needed.
    if (total_sum == s) {
        cout << 0 << "\n";
        return;
    }

    // We need to find the longest subarray with a sum of 's'.
    // The number of operations will be n minus the length of this subarray.
    // We use a sliding window [left, right] to find this.
    int max_len = 0;
    long long current_sum = 0;
    int left = 0;
    for (int right = 0; right < n; ++right) {
        // Expand the window by adding the element at the 'right' pointer.
        current_sum += a[right];

        // If the sum exceeds 's', shrink the window from the 'left'.
        while (current_sum > s) {
            current_sum -= a[left];
            left++;
        }

        // If the current window's sum is exactly 's', it's a valid subarray.
        // We update our maximum length found so far.
        if (current_sum == s) {
            max_len = max(max_len, right - left + 1);
        }
    }

    // The minimum operations is the total length minus the longest subarray we can keep.
    cout << n - max_len << "\n";
}

int main() {
    // Fast I/O for competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}