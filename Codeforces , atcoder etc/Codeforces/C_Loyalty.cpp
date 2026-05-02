#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long x;
    cin >> n >> x;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Sort to access smallest and largest easily
    sort(a.begin(), a.end());
    
    vector<long long> res;
    res.reserve(n);
    
    long long bonus = 0;
    long long current_rem = 0;
    int l = 0, r = n - 1;
    
    while(l <= r) {
        // If only one element remains
        if (l == r) {
            if (current_rem + a[r] >= x) {
                bonus += a[r];
            }
            res.push_back(a[r]);
            break;
        }

        // Try to trigger bonus with the largest available item
        if (current_rem + a[r] >= x) {
            bonus += a[r];
            current_rem = (current_rem + a[r]) % x;
            res.push_back(a[r]);
            r--;
        } else {
            // Cannot trigger with largest; use smallest as filler
            current_rem += a[l];
            res.push_back(a[l]);
            l++;
        }
    }
    
    cout << bonus << "\n";
    for(int i = 0; i < n; i++) {
        cout << res[i] << (i == n - 1 ? "" : " ");
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