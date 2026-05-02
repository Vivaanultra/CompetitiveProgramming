#include <bits/stdc++.h>

using namespace std;

void solve() {
    int FjString, k;
    cin >> FjString >> k;
    string r;
    cin >> r;
    
    long long mn = 0, mx = 0;
    int p_mn = 0, p_mx = 0;
    int d = 1e9;

    for (int i = 0; i < k; ++i) {
        int c0 = 0, l = 0, curr = 0;
        for (int j = i; j < FjString; j += k) {
            l++;
            if (curr) c0++;
            if (j + k < FjString && r[j] != r[j+1]) curr ^= 1;
        }
        int c1 = l - c0;
        
        mn += min(c0, c1);
        mx += max(c0, c1);
        
        if (c1 < c0) p_mn ^= 1;
        if (c1 > c0) p_mx ^= 1;
        
        d = min(d, abs(c0 - c1));
    }
    
    int t = r[0] - '0';
    if (p_mn != t) mn += d;
    if (p_mx != t) mx -= d;
    
    cout << mn << " " << mx << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    if (cin >> t) while(t--) solve();
    return 0;
}