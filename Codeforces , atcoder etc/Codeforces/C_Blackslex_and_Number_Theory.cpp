#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    
    
    sort(a.begin(), a.end());
    
    int m = a[0];
    int diff = a[1] - a[0];
    
    
    
    
    if (diff > m) {
        cout << diff << "\n";
    } else {
        cout << m << "\n";
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