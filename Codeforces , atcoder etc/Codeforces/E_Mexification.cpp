#include <bits/stdc++.h>
using namespace std;

// The efficient O(N) transformation function.
vector<long long> transform(int n, const vector<long long>& a) {
    vector<int> freq(n + 2, 0);
    for (long long x : a) {
        if (x <= n) {
            freq[x]++;
        }
    }

    long long m = 0;
    while (m <= n && freq[m] > 0) {
        m++;
    }

    vector<long long> next_a(n);
    for (int i = 0; i < n; ++i) {
        long long val = a[i];
        bool is_unique = (val <= n && freq[val] == 1);
        if (is_unique && val < m) {
            next_a[i] = val;
        } else {
            next_a[i] = m;
        }
    }
    return next_a;
}

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Map to store seen states and the step they appeared at.
    map<vector<long long>, long long> history;
    // Vector to retrieve the array at a specific step.
    vector<vector<long long>> states;

    for (long long step = 0; step < k; ++step) {
        // Check if we've seen this state before (cycle detected).
        if (history.count(a)) {
            long long prev_step = history[a];
            long long cycle_len = step - prev_step;
            long long remaining_k = k - step;
            a = states[prev_step + (remaining_k % cycle_len)];
            goto end_simulation; // Jump out of the loop.
        }

        // Store the current state.
        history[a] = step;
        states.push_back(a);
        
        // Compute the next state.
        a = transform(n, a);
    }

end_simulation:
    long long final_sum = 0;
    for (long long x : a) {
        final_sum += x;
    }
    cout << final_sum << "\n";
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