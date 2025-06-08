
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    int odd = 0, even = 0;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] % 2) odd++;
        else even++;
    }
    
    bool possible = false;
    for(int i = 1; i <= odd && i <= x; i += 2) {
        int remaining = x - i;
        if(remaining <= even) {
            possible = true;
            break;
        }
    }
    
    cout << (possible ? "Yes" : "No") << endl;
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
