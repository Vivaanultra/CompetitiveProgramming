#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// Using competitive programming practices
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long current_sum = 0; // Use long long for the sum to avoid overflow
    int max_element = 0;       // Keeps track of the max element in the current prefix
    int good_prefixes_count = 0;

    // This loop represents the "growing window" (our prefix)
    for (int i = 0; i < n; ++i) {
        // Extend the window to the right by one element
        current_sum += a[i];
        max_element = max(max_element, a[i]);

        // Check the condition for the current prefix a[0...i]
        // We must cast max_element to long long before multiplying by 2
        // to prevent potential overflow if max_element is large.
        if (current_sum == 2LL * max_element) {
            good_prefixes_count++;
        }
    }

    cout << good_prefixes_count << endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve();
    }

    return 0;
}