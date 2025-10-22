#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int crossings = 0;
    
    // Use nested loops to check every pair of indices (i, j) where i < j
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // A crossing can be made if the endpoints are "inverted"
            if (a[i] >= a[j]) {
                crossings++;
            }
        }
    }

    cout << crossings << endl;
}

int main() {
    // It is currently Sunday, 6:46 PM in Mathura, India.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}