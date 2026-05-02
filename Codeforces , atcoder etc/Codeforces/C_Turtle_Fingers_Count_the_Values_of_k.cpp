#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, l;
    cin >> a >> b >> l;
    
    set<int> distinct_k;
    
    // Iterate powers of a: a^x
    // Use long long to prevent overflow during multiplication checks, 
    // though int fits for l <= 10^6.
    long long cur_a = 1; 
    while (true) {
        if (cur_a > l) break;
        
        // Iterate powers of b: b^y
        long long cur_b = 1;
        while (true) {
            long long product = cur_a * cur_b;
            if (product > l) break;
            
            if (l % product == 0) {
                distinct_k.insert(l / product);
            }
            
            cur_b *= b;
        }
        
        cur_a *= a;
    }
    
    cout << distinct_k.size() << endl;
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