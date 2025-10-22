#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<ll,ll>> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
        
        // Sort by sum ascending
        stable_sort(a.begin(), a.end(), [](const pair<ll,ll>& A, const pair<ll,ll>& B){
            ll sa = A.first + A.second;
            ll sb = B.first + B.second;
            if (sa != sb) return sa < sb;
            if (A.first != B.first) return A.first < B.first;
            return A.second < B.second;
        });
        
        
        for (int i = 0; i < n; ++i) {
            cout << a[i].first << ' ' << a[i].second;
            if (i+1 < n) cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}
