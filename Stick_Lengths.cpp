#include <bits/stdc++.h>
using namespace std;

// Use long long to prevent overflow
using ll = long long;

int main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    vector<ll> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }

    // Sort to find the median
    sort(p.begin(), p.end());

    // The median minimizes the sum of absolute differences
    ll median = p[n/2];
    ll cost = 0;

    for(int i = 0; i < n; i++) {
        cost += abs(p[i] - median);
    }

    cout << cost << "\n";

    return 0;
}