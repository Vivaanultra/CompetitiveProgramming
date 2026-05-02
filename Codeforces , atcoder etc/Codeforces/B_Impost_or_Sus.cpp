#include <bits/stdc++.h>
using namespace std;

void solve() {
    string r;
    cin >> r;
    int n = r.length();
    
    vector<int> dp(n);
    
    
    dp[0] = (r[0] == 'u');
    
    for (int i = 1; i < n; i++) {
        
        assert(r[i] == 's' || r[i] == 'u');
        
        int cost = (r[i] == 'u');
        
        if (i == 1) {
            
            dp[i] = dp[i-1] + cost;
        } else {
            
            dp[i] = min(dp[i-1], dp[i-2]) + cost;
        }
    }
    
    
    cout << dp[n-1] << "\n";
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