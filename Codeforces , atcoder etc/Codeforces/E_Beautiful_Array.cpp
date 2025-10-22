#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)4e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        // group by residue mod k
        unordered_map<ll, vector<ll>> mp;
        mp.reserve(n*2);
        for(ll x: a){
            ll r = ((x % k) + k) % k;
            mp[r].push_back(x);
        }

        // count how many groups have odd size
        int odd_groups = 0;
        for(auto &kv: mp){
            if((kv.second.size() & 1)) 
                odd_groups++;
        }
        // must have at most one odd group, and parity matches
        if(odd_groups > 1){
            cout << -1 << "\n";
            continue;
        }

        ll raw_cost = 0;  // we'll sum actual differences, then divide by k
        bool bad = false;

        for(auto &kv: mp){
            auto &v = kv.second;
            int m = v.size();
            sort(v.begin(), v.end());
            // build diffs
            vector<ll> diff(max(0,m-1));
            for(int i = 0; i+1 < m; i++){
                diff[i] = v[i+1] - v[i];  
                // must be multiple of k
                if(diff[i] % k != 0){
                    bad = true;
                }
            }
            if(bad) break;

            if((m & 1) == 0){
                // even: just pair (0,1),(2,3),...
                for(int i = 0; i < m; i += 2){
                    raw_cost += diff[i];
                }
            } else {
                // odd: run DP letting us skip exactly one element
                // dp0[i] = min cost to fully pair first i elems with NO skip used
                // dp1[i] = min cost to fully pair first i elems WITH skip used
                vector<ll> dp0(m+1, INF), dp1(m+1, INF);
                dp0[0] = 0;
                // we can skip the very first element:
                dp1[1] = 0;

                for(int i = 2; i <= m; i++){
                    // pairing last two of those i:
                    ll d = diff[i-2];
                    // no skip used so far, pair (i-2,i-1)
                    if(dp0[i-2] != INF)
                        dp0[i] = dp0[i-2] + d;
                    // skip already used, pair
                    if(dp1[i-2] != INF)
                        dp1[i] = dp1[i-2] + d;
                    // use skip right now on element i-1
                    // that consumes a skip and does not add cost
                    dp1[i] = min(dp1[i], dp0[i-1]);
                }
                // answer for this odd class is dp1[m]
                raw_cost += dp1[m];
            }
        }

        if(bad){
            cout << -1 << "\n";
        } else {
            // every +k adds exactly k to value, so each unit of raw_cost
            // corresponds to a multiple of k.  Number of ops = raw_cost / k
            cout << (raw_cost / k) << "\n";
        }
    }

    return 0;
}
