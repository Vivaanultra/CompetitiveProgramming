#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    long long sum = 0;
    bool has_rem_1 = false;
    
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        sum += a;
        if (a % 3 == 1) {
            has_rem_1 = true;
        }
    }
    
    int rem = sum % 3;
    
    if (rem == 0) {
        cout << 0 << endl;
    } else if (rem == 2) {
        cout << 1 << endl;
    } else {
        if (has_rem_1) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
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