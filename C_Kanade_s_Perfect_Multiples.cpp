#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    int m = a.size();
    vector<bool> redundant(m, false);

    for(int i = 0; i < m; i++) {
        long long val = a[i];
        for(long long multiple = 2 * val; multiple <= k; multiple += val) {
            auto it = lower_bound(a.begin(), a.end(), multiple);
            if(it == a.end() || *it != multiple) {
                cout << -1 << "\n";
                return;
            }
            redundant[it - a.begin()] = true;
        }
    }

    vector<long long> ans;
    for(int i = 0; i < m; i++) {
        if(!redundant[i]) ans.push_back(a[i]);
    }

    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}