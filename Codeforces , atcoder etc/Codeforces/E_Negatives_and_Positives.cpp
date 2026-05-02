#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    long long sum = 0;
    int min_abs = INT_MAX;
    int neg_cnt = 0;
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a < 0) neg_cnt++;
        sum += abs(a);
        min_abs = min(min_abs, abs(a));
    }
    
    if (neg_cnt % 2 != 0) {
        sum -= 2LL * min_abs;
    }
    
    cout << sum << endl;
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