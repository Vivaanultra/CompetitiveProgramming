#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    long long c;
    cin >> n >> c;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Sort the bags from heaviest to lightest to prioritize the hardest problems.
    sort(a.rbegin(), a.rend());

    // 'saved' counts the number of bags we successfully destroy for free.
    // It also represents the next available time slot (t=0, t=1, ...).
    int saved = 0;
    for (long long weight : a) {
        // Check if the current bag can be destroyed for free at the next
        // available time slot 't = saved'.
        if (weight * (1LL << saved) <= c) {
            saved++;
        }
    }

    // The total cost is the number of bags we couldn't save for free.
    cout << n - saved << endl;
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