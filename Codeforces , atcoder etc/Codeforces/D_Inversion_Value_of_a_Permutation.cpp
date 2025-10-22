#include <bits/stdc++.h>
using namespace std;
int C2(int x){ return x*(x-1)/2; }
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin>>t)) return 0;
    while(t--){
        int n;
        long long k;
        cin>>n>>k;
        int total = C2(n);
        if(k<0 || k>total){
            cout<<"0\n";
            continue;
        }
        int m = total - (int)k;
        int maxM = total;
        vector<vector<int>> memo(n+1, vector<int>(maxM+1, -1));
        function<int(int,int)> dfs = [&](int rem,int need)->int{
            if(need<0) return 0;
            if(rem==0) return need==0;
            if(need> C2(rem)) return 0;
            int &me = memo[rem][need];
            if(me!=-1) return me;
            for(int x=1;x<=rem;++x){
                int v = C2(x);
                if(v>need) break;
                if(dfs(rem-x, need-v)){
                    me = x;
                    return me;
                }
            }
            me = 0;
            return me;
        };
        if(!dfs(n,m)){
            cout<<"0\n";
            continue;
        }
        vector<int> blocks;
        int rem = n, need = m;
        while(rem>0){
            int x = memo[rem][need];
            if(x==0) break;
            blocks.push_back(x);
            need -= C2(x);
            rem -= x;
        }
        if(rem!=0){
            cout<<"0\n";
            continue;
        }
        vector<int> ans;
        int cur = n;
        for(int b: blocks){
            int start = cur - b + 1;
            for(int v = start; v<=cur; ++v) ans.push_back(v);
            cur -= b;
        }
        for(int i=0;i<n;i++){
            if(i) cout<<' ';
            cout<<ans[i];
        }
        cout<<"\n";
    }
    return 0;
}
