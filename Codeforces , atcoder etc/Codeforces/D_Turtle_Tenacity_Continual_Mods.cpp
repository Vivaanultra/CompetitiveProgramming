#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int min_val = INT_MAX;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        min_val = min(min_val, a[i]);
    }
    
    int count_min = 0;
    for (int x : a) {
        if (x == min_val) {
            count_min++;
        }
    }
    
    if (count_min == 1) {
        cout << "YES" << endl;
        return;
    }
    
    for (int x : a) {
        if (x % min_val != 0) {
            cout << "YES" << endl;
            return;
        }
    }
    
    cout << "NO" << endl;
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