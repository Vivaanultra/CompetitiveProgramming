#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int bottom_count = 0;
    
    int i = 0;
    while (i < n) {
        // Find the end of the current flat plateau
        int j = i;
        while (j + 1 < n && a[j + 1] == a[j]) {
            j++;
        }

        // Now we have a plateau from i to j
        bool left_ok = (i == 0) || (a[i - 1] > a[i]);
        bool right_ok = (j == n - 1) || (a[j] < a[j + 1]);

        if (left_ok && right_ok) {
            bottom_count++;
        }

        // Move to the next new number
        i = j + 1;
    }

    if (bottom_count == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    // It is currently Friday, 5:05 PM in Mathura, India.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}