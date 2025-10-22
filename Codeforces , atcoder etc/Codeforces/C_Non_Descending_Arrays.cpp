#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin>>T)) return 0;
    while(T--){
        int n; cin>>n;
        vector<int>a(n), b(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        ll prev0 = 1, prev1 = 1;
        for(int i=1;i<n;i++){
            ll cur0 = 0, cur1 = 0;
            if(a[i-1] <= a[i] && b[i-1] <= b[i]) cur0 = (cur0 + prev0) % MOD;
            if(b[i-1] <= a[i] && a[i-1] <= b[i]) cur0 = (cur0 + prev1) % MOD;
            if(a[i-1] <= b[i] && b[i-1] <= a[i]) cur1 = (cur1 + prev0) % MOD;
            if(b[i-1] <= b[i] && a[i-1] <= a[i]) cur1 = (cur1 + prev1) % MOD;
            prev0 = cur0; prev1 = cur1;
        }
        cout << (prev0 + prev1) % MOD << '\n';
    }
    return 0;
}
