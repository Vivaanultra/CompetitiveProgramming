#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << a[0] << endl;
        return;
    }

    // Step 1: Sort the array
    sort(a.begin(), a.end());

    // The first candidate for the answer is the original minimum
    long long max_of_mins = a[0];

    // Check the differences between all adjacent elements
    for (int i = 1; i < n; ++i) {
        long long diff = a[i] - a[i-1];
        max_of_mins = max(max_of_mins, diff);
    }

    cout << max_of_mins << endl;
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