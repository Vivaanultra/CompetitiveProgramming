#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    cout << (1 << n) - 1 << " ";
    
    for (int dropped = n - 1; dropped >= 0; dropped--) {
        int fixed_mask = (1 << dropped) - 1;
        int shift = dropped + 1;
        int count = 1 << (n - 1 - dropped);
        
        for (int i = 0; i < count; i++) {
            cout << (fixed_mask | (i << shift)) << " ";
        }
    }
    cout << "\n";
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