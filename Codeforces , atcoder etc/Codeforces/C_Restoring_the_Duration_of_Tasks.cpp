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
    vector<long long> s(n), f(n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) cin >> f[i];

    // The duration of the first task is straightforward.
    // Start time is s[0], finish time is f[0].
    cout << f[0] - s[0];

    // For all subsequent tasks...
    for (int i = 1; i < n; ++i) {
        // The start time for task 'i' is the later of two events:
        // 1. When the previous task (i-1) was finished (f[i-1]).
        // 2. When task 'i' itself arrived (s[i]).
        long long start_time = max(f[i - 1], s[i]);
        
        // The duration is the given finish time minus our calculated start time.
        long long duration = f[i] - start_time;
        cout << " " << duration;
    }

    cout << endl;
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