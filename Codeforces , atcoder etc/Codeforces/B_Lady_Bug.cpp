#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while(t--){
        int n; 
        string a,b;
        cin >> n >> a >> b;

        int topOnes[2] = {0,0}, freeSlots[2] = {0,0};

        for(int i = 0; i < n; i++){
            int pa = ((i+1) + 1) & 1; // bucket of a[i]
            int pb = ((i+1) + 2) & 1; // bucket of b[i]
            if(a[i] == '1')    topOnes[pa]++;
            if(b[i] == '0')    freeSlots[pb]++;
        }

        bool ok = true;
        for(int p = 0; p < 2; p++){
            if(topOnes[p] > freeSlots[p]){
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
