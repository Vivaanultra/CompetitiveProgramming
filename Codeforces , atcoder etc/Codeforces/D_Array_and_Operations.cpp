#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long score = 0;
    
    // Add the sum of the n - 2k smallest leftover elements
    for (int i = 0; i < n - 2 * k; ++i) {
        score += a[i];
    }
    
    // Add the score from the k division operations
    for (int i = 0; i < k; ++i) {
        score += a[n - 2 * k + i] / a[n - k + i];
    }

    cout << score << endl;
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