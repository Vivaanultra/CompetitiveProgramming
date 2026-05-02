#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long c;
    cin >> n >> c;
    vector<long long> costs;
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        // Cost is distance (i + 1) + activation cost (a)
        costs.push_back(a + (i + 1LL));
    }
    
    sort(costs.begin(), costs.end());
    
    int ans = 0;
    for (long long cost : costs) {
        if (c >= cost) {
            c -= cost;
            ans++;
        } else {
            break;
        }
    }
    
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}