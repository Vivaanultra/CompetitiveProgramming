#include <bits/stdc++.h>
using namespace std;




long long calc_gain(long long S, long long u) {
    return S * u - S * (S - 1) / 2;
}

void solve() {
    int n;
    cin >> n;
    
    
    vector<long long> a(n + 1);
    vector<long long> pref(n + 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    
    int q;
    cin >> q;
    while (q--) {
        int l;
        long long u;
        cin >> l >> u;
        
        
        
        
        long long target = pref[l - 1] + u;
        
        
        int r_idx = lower_bound(pref.begin() + l, pref.end(), target) - pref.begin();
        
        
        
        if (r_idx > n) r_idx = n;
        
        
        int r_prev = r_idx - 1;
        
        
        
        if (r_prev < l) {
            cout << r_idx << " ";
            continue;
        }
        
        
        long long S1 = pref[r_idx] - pref[l - 1];
        long long gain1 = calc_gain(S1, u);
        
        long long S2 = pref[r_prev] - pref[l - 1];
        long long gain2 = calc_gain(S2, u);
        
        
        if (gain1 > gain2) {
            cout << r_idx << " ";
        } else {
            cout << r_prev << " ";
        }
    }
    cout << endl;
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