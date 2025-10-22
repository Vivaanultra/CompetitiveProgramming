#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    map<int, int> required;
    required[0] = 3; 
    required[1] = 1;
    required[2] = 2;
    required[3] = 1;
    required[5] = 1;

    int total_needed = 8;
    for (int i = 0; i < n; ++i) {
        if (required.count(a[i]) && required[a[i]] > 0) {
            required[a[i]]--;
            total_needed--;
            if (total_needed == 0) {
                cout << i + 1 << endl;
                return;
            }
        }
    }
    cout << 0 << endl;
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