#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    long long h; 
    cin >> n >> m >> h;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    
    vector<long long> b = a;
    
    
    vector<int> history; 

    while (m--) {
        int idx;
        long long val;
        cin >> idx >> val;
        idx--; 

        b[idx] += val;
        history.push_back(idx); 

        if (b[idx] > h) {
            
            
            for (int changed_idx : history) {
                b[changed_idx] = a[changed_idx];
            }
            
            history.clear();
        }
    }

    for (int i = 0; i < n; i++) {
        cout << b[i] << (i == n - 1 ? "" : " ");
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