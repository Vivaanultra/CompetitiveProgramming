#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    vector<ll> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    ll max_so_far = -1e18; 
    ll current_sum = 0;

    for (int i = 0; i < n; i++) {
        
        
        if (current_sum + x[i] < x[i]) {
            current_sum = x[i];
        } else {
            current_sum += x[i];
        }
        
        max_so_far = max(max_so_far, current_sum);
    }

    cout << max_so_far << "\n";

    return 0;
}