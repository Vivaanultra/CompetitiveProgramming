#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int64> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        bool ok = true;
        for(int i = 0; i < n; i++){
            // distance to nearer end:
            // but we need the longer side max(i, n-1-i)
            int64 d = max<int64>(i, n-1 - i);
            int64 required = 2*d + 1;
            if(a[i] < required){
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
