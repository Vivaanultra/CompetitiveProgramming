#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> total_counts;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_counts[a[i]]++;
    }

    // Step 1: Check divisibility and calculate targets
    map<int, int> target;
    bool possible = true;
    for (auto const& [val, count] : total_counts) {
        if (count % k != 0) {
            possible = false;
            break;
        }
        target[val] = count / k;
    }

    if (!possible) {
        cout << 0 << "\n";
        return;
    }

    // Step 2: Two Pointers (Sliding Window)
    long long awesome_subarrays = 0;
    int left = 0;
    map<int, int> window_counts;

    for (int right = 0; right < n; ++right) {
        // Add the new element to the window
        window_counts[a[right]]++;

        // While the window is not awesome, shrink from the left
        while (window_counts[a[right]] > target[a[right]]) {
            window_counts[a[left]]--;
            left++;
        }

        // The window [left, right] is the largest awesome subarray ending at 'right'.
        // All subarrays [l', right] where left <= l' <= right are also awesome.
        awesome_subarrays += (right - left + 1);
    }

    cout << awesome_subarrays << "\n";
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