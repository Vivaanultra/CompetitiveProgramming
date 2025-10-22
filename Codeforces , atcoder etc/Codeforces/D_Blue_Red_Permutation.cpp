#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    string colors;
    cin >> colors;

    vector<int> reds;
    vector<int> blues;
    for (int i = 0; i < n; ++i) {
        if (colors[i] == 'R') {
            reds.push_back(a[i]);
        } else {
            blues.push_back(a[i]);
        }
    }

    sort(reds.begin(), reds.end());
    sort(blues.begin(), blues.end());

    // Check 1: The "Small Blue" traffic jam
    // The i-th smallest blue number (1-indexed) is blues[i-1].
    // It must be large enough to be mapped to at least target `i`.
    for (int i = 0; i < blues.size(); ++i) {
        if (blues[i] < (i + 1)) {
            cout << "NO" << endl;
            return;
        }
    }

    // Check 2: The "Large Red" traffic jam
    // The i-th smallest red number is reds[i].
    // It must be small enough to be mapped to at least target `i + blues.size() + 1`.
    for (int i = 0; i < reds.size(); ++i) {
        // The target slots for reds start after the slots potentially taken by blues.
        // The (i+1)-th smallest red, which is reds[i], must map to a target.
        // The (i+1)-th available slot for it is i + 1.
        // The available slots for reds are [1,n].
        // The i-th largest red must be <= n - i + 1
        // The i-th smallest red must be <= the target slot it's aiming for.
        int target = i + 1 + blues.size();
        if (reds[i] > target) {
            cout << "NO" << endl;
            return;
        }
    }
    
    cout << "YES" << endl;
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