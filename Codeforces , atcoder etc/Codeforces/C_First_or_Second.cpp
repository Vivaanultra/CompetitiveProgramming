#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long current_x = 0;
    
    for(int i = 1; i < n; ++i) {
        current_x -= a[i];
    }

    long long max_x = current_x;

    for(int k = 0; k < n - 1; ++k) {
        current_x += a[k+1];
        if (k == 0) {
            current_x += a[k];
        } else {
            current_x += abs(a[k]);
        }
        max_x = max(max_x, current_x);
    }

    cout << max_x << "\n";
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