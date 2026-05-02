#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    
    // Using 1-based indexing
    vector<ll> a(n + 1);
    vector<ll> P(n + 1, 0);
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        P[i] = P[i-1] + a[i];
    }

    ll total_sum = P[n];
    ll max_gain = 0; // Initialize to 0 (case where we make no changes)
    
    // We want to maximize: (R_val - L_val)
    // R_val(r) = r*r + r - P[r]
    // L_val(l) = l*l - l - P[l-1]   <-- CORRECTED SIGN
    
    ll min_L_val = 2e18; // Start with infinity

    for(ll i = 1; i <= n; i++) {
        // 1. Update min_L_val treating current 'i' as a potential start 'l'
        // Formula: l*l - l - P[l-1]
        ll current_L_val = (i * i) - i - P[i-1];
        min_L_val = min(min_L_val, current_L_val);
        
        // 2. Treat current 'i' as the end point 'r'
        // Formula: r*r + r - P[r]
        ll current_R_val = (i * i) + i - P[i];
        
        // 3. Calculate max gain ending at 'i'
        ll current_gain = current_R_val - min_L_val;
        
        max_gain = max(max_gain, current_gain);
    }

    cout << total_sum + max_gain << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while(t--) {
            solve();
        }
    }
    return 0;
}