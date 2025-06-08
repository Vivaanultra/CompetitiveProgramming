#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int test = 0; test < t; test++) {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        ll sum = 0;
        for(int i = 0; i < n; i++) sum += a[i];
        vector<ll> prefix_min(n), prefix_max(n), suffix_min(n), suffix_max(n);
        prefix_min[0] = a[0];
        prefix_max[0] = a[0];
        for(int i = 1; i < n; i++) {
            prefix_min[i] = min(prefix_min[i-1], a[i]);
            prefix_max[i] = max(prefix_max[i-1], a[i]);
        }
        suffix_min[n-1] = a[n-1];
        suffix_max[n-1] = a[n-1];
        for(int i = n-2; i >= 0; i--) {
            suffix_min[i] = min(suffix_min[i+1], a[i]);
            suffix_max[i] = max(suffix_max[i+1], a[i]);
        }
        bool has_legal_move = false;
        for(int i = 0; i < n; i++) {
            if(a[i] > 0) {
                ll min_other;
                if(i == 0 && n > 1) min_other = suffix_min[1];
                else if(i == n-1 && n > 1) min_other = prefix_min[n-2];
                else if(n == 1) min_other = LLONG_MAX; // No other elements
                else min_other = min(prefix_min[i-1], suffix_min[i+1]);
                ll max_other;
                if(i == 0 && n > 1) max_other = suffix_max[1];
                else if(i == n-1 && n > 1) max_other = prefix_max[n-2];
                else if(n == 1) max_other = LLONG_MIN; // No other elements
                else max_other = max(prefix_max[i-1], suffix_max[i+1]);
                ll m_prime = min(min_other, a[i]-1);
                ll M_prime = max(max_other, a[i]-1);
                if(M_prime - m_prime <= k) {
                    has_legal_move = true;
                    break;
                }
            }
        }
        if(has_legal_move) {
            if(sum % 2 == 1) cout << "Tom" << endl;
            else cout << "Jerry" << endl;
        } else {
            cout << "Jerry" << endl;
        }
    }
    return 0;
}