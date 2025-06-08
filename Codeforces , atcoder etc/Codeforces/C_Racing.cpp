#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> d(n+1);
        for(int i=1;i<=n;i++){
            cin >> d[i];
        }
        vector<int> L(n+1), R(n+1);
        for(int i=1;i<=n;i++){
            cin >> L[i] >> R[i];
        }

        // forward: compute low[i], high[i]
        vector<int> low(n+1), high(n+1);
        low[0] = high[0] = 0;
        bool ok = true;
        for(int i=1;i<=n;i++){
            ll nl, nh;
            if(d[i] == 0){
                nl = low[i-1];
                nh = high[i-1];
            } else if(d[i] == 1){
                nl = low[i-1] + 1;
                nh = high[i-1] + 1;
            } else {
                // unknown: could stay or rise
                nl = low[i-1];
                nh = high[i-1] + 1;
            }
            // intersect with obstacle [L[i],R[i]]
            nl = max<ll>(nl, L[i]);
            nh = min<ll>(nh, R[i]);
            if(nl > nh){
                ok = false;
                break;
            }
            low[i] = nl;
            high[i] = nh;
        }

        if(!ok){
            cout << -1 << "\n";
            continue;
        }

        // backward: reconstruct actual d and h
        vector<int> h(n+1);
        h[n] = low[n];  // pick any feasible final height
        for(int i=n; i>=1; i--){
            if(d[i] == 0 || d[i] == 1){
                // fixed
                h[i-1] = h[i] - d[i];
            } else {
                // try d[i]=0 if h[i-1]=h[i] fits low[i-1]..high[i-1]
                if(h[i] >= low[i-1] && h[i] <= high[i-1]){
                    d[i] = 0;
                    h[i-1] = h[i];
                } else {
                    // must be 1
                    d[i] = 1;
                    h[i-1] = h[i] - 1;
                }
            }
        }

        // output
        for(int i=1;i<=n;i++){
            cout << d[i] << (i==n?'\n':' ');
        }
    }

    return 0;
}
