#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    bool has_symmetric = false;
    
    // Process all n tiles
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b; // Top-left, Top-right
        cin >> c >> d; // Bottom-left, Bottom-right
        
        // Check if the tile is symmetric (top-right == bottom-left)
        if (b == c) {
            has_symmetric = true;
        }
    }
    
    // Check constraints: m must be even AND we need at least one symmetric tile
    if (m % 2 == 0 && has_symmetric) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}