#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    bool neg = false;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] < 0) neg = true;
    }
    
    if(neg) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << 101 << endl;
        for(int i = 0; i <= 100; i++) {
            cout << i << (i == 100 ? "" : " ");
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}