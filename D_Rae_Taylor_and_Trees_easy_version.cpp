#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    long long current_prefix_sum = 0;
    
    
    for (int k = 1; k < n; k++) {
        current_prefix_sum += p[k - 1];
        
        
        
        
        
        long long first = n - k + 1;
        long long last = n;
        long long target_sum = (long long)k * (first + last) / 2;

        
        
        
        
        if (current_prefix_sum == target_sum) {
            cout << "No" << "\n";
            return;
        }
    }

    cout << "Yes" << "\n";
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