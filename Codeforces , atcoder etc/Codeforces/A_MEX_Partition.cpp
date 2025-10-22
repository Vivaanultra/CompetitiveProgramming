#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<bool> seen(101, false);
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (val <= 100) {
            seen[val] = true;
        }
    }

    int mex = 0;
    while (mex <= 100 && seen[mex]) {
        mex++;
    }
    
    cout << mex << endl;
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