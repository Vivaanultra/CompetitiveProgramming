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

    sort(x.begin(), x.end());

    ll current_sum = 0;

    for (int i = 0; i < n; i++) {
        // If the current coin is too large, we can't form current_sum + 1
        if (x[i] > current_sum + 1) {
            break; 
        }
        current_sum += x[i];
    }

    cout << current_sum + 1 << "\n";

    return 0;
}