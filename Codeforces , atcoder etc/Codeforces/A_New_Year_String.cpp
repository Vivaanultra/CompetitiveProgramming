#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    
    
    
    int ops_avoid_2025 = 0;
    for (int i = 0; i <= n - 4; ) {
        if (s.substr(i, 4) == "2025") {
            ops_avoid_2025++;
            i += 4; 
        } else {
            i++;
        }
    }

    
    
    int ops_make_2026 = 1e9; 
    
    if (n >= 4) {
        for (int i = 0; i <= n - 4; ++i) {
            int current_cost = 0;
            string target = "2026";
            
            
            for (int j = 0; j < 4; ++j) {
                if (s[i + j] != target[j]) {
                    current_cost++;
                }
            }
            ops_make_2026 = min(ops_make_2026, current_cost);
        }
    }

    
    cout << min(ops_avoid_2025, ops_make_2026) << endl;
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