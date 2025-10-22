#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin>>T)) return 0;
    for(int tc=1;tc<=T;++tc){
        int N; cin>>N;
        vector<int>A(N+1),B(N+1);
        for(int i=1;i<=N;++i) cin>>A[i];
        for(int i=1;i<=N;++i) cin>>B[i];
        bool ok=true;
        for(int i=1;i<=N;++i) if(A[i]>B[i]) ok=false;
        vector<vector<int>> posA(N+1), need(N+1);
        for(int i=1;i<=N;++i) posA[A[i]].push_back(i);
        for(int i=1;i<=N;++i) if(B[i]!=A[i]) need[B[i]].push_back(i);
        for(int v=1;v<=N;++v){
            if(!need[v].empty() && posA[v].empty()) ok=false;
        }
        if(!ok){
            cout<<"Case #"<<tc<<": -1\n";
            continue;
        }
        vector<pair<int,int>> ops;
        for(int v=1;v<=N;++v){
            if(need[v].empty()) continue;
            int donor = posA[v][0];
            for(int idx: need[v]){
                if(A[idx]<v){
                    ops.emplace_back(idx, donor);
                    A[idx]=v;
                }
            }
        }
        cout<<"Case #"<<tc<<": "<<ops.size()<<"\n";
        for(auto &p: ops) cout<<p.first<<" "<<p.second<<"\n";
    }
    return 0;
}
