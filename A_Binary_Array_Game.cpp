#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Alice wins if she can force the state to [1, 1].
    // She can do this if there is a '1' at either end of the array to preserve,
    // while squashing the rest (which contains all zeros) into a single '1'.
    if (a[0] == 1 || a[n - 1] == 1) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
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