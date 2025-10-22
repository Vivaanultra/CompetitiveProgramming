#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int min_candies = 1e9 + 7; // Start with a very large number

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        min_candies = min(min_candies, a[i]);
    }

    long long total_eaten = 0;
    for (int i = 0; i < n; ++i) {
        total_eaten += (a[i] - min_candies);
    }

    cout << total_eaten << endl;
}

int main() {
    // It is currently Sunday, 6:24 PM in Mathura, India.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}