#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    
    // We target a GCD of (k + 1).
    // Since k = -1 mod (k + 1), adding k is like subtracting 1.
    // To make a_i divisible by k+1, we add k exactly (a_i % (k+1)) times.
    
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        
        long long x = a % (k + 1);
        long long result = a + x * k;
        
        cout << result << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
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