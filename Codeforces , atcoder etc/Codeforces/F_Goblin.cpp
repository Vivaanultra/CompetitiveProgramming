#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU {
    vector<int> p;
    vector<ll> sz;
    DSU(int n): p(n), sz(n,0) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x){
        return p[x]==x ? x : p[x]=find(p[x]);
    }
    void unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a==b) return;
        // union by size
        if(sz[a] < sz[b]) 
            swap(a,b);
        p[b] = a;
        sz[a] += sz[b];
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n;
        string s;
        cin >> n >> s;
        s = " " + s;  // 1-index

        // 1) find all runs of zeros in s
        vector<pair<int,int>> segs;
        vector<int> segAt(n+2, -1);
        for(int i=1; i<=n; ){
            if(s[i]=='0'){
                int L = i;
                while(i<=n && s[i]=='0') i++;
                int R = i-1;
                segs.emplace_back(L,R);
                int idx = segs.size()-1;
                for(int j=L; j<=R; j++)
                    segAt[j] = idx;
            } else {
                i++;
            }
        }

        int segCnt = segs.size();
        // We'll have two DSU nodes per segment: compUpper = 2*idx, compLower = 2*idx+1
        // plus one per diagonal-zero.
        // First count how many diag-zeros we have:
        vector<int> diagID(n+2, -1);
        int diagCnt = 0;
        for(int j=1; j<=n; j++){
            if(s[j]=='1'){
                diagID[j] = segCnt*2 + (diagCnt++);
            }
        }

        DSU dsu(segCnt*2 + diagCnt);

        // 2) initialize weights: for each off-diag comp node
        for(int idx=0; idx<segCnt; idx++){
            auto [L,R] = segs[idx];
            ll m = R - L + 1;
            // U = sum_{j=L..R} (j-1)
            ll U = (ll)R*(R-1)/2 - (ll)(L-1)*(L-2)/2;
            // D = sum_{j=L..R} (n-j) = m*n - sum_{j=L..R} j
            ll sumj = (ll)R*(R+1)/2 - (ll)(L-1)*L/2;
            ll D = m*(ll)n - sumj;

            int cu = idx*2, cl = idx*2+1;
            dsu.sz[cu] = U;
            dsu.sz[cl] = D;
        }
        // diag-zeros start with weight=1
        for(int j=1; j<=n; j++){
            if(s[j]=='1'){
                dsu.sz[ diagID[j] ] = 1;
            }
        }

        // 3) hook up each diag-zero into the comps it neighbors
        for(int j=1; j<=n; j++){
            if(s[j]=='1'){
                int id = diagID[j];
                // neighbor on the left -> lower comp of segment at j-1
                if(j>1 && segAt[j-1]!=-1){
                    int seg = segAt[j-1];
                    int cl = seg*2+1;
                    dsu.unite(id, cl);
                }
                // neighbor on the right -> upper comp of segment at j+1
                if(j<n && segAt[j+1]!=-1){
                    int seg = segAt[j+1];
                    int cu = seg*2;
                    dsu.unite(id, cu);
                }
            }
        }

        // 4) scan for the maximum DSU component weight
        ll ans = 0;
        int N = segCnt*2 + diagCnt;
        for(int i=0; i<N; i++){
            if(dsu.find(i)==i){
                ans = max(ans, dsu.sz[i]);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
