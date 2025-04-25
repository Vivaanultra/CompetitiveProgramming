#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n, q;
        cin >> n >> q;
        vector<int> p(n+1), pos(n+1);
        for(int i = 1; i <= n; i++){
            cin >> p[i];
            pos[p[i]] = i;
        }

        while(q--){
            int l, r, x;
            cin >> l >> r >> x;
            int px = pos[x];
            // x must lie in [l,r] to ever be found
            if(px < l || px > r){
                cout << -1 << "\n";
                continue;
            }

            int lo = l, hi = r;
            int badL = 0, badR = 0;
            // simulate the path that *would* find x
            while(lo <= hi){
                int mid = (lo + hi) >> 1;
                if(mid == px) 
                    break;
                if(mid < px){
                    // desired: p[mid] < x
                    if(p[mid] > x) 
                        badL++;
                    lo = mid + 1;
                } else {
                    // mid > px; desired: p[mid] > x
                    if(p[mid] < x) 
                        badR++;
                    hi = mid - 1;
                }
            }

            // check if we can source enough small / large values
            if(badL > x - 1 || badR > n - x){
                cout << -1 << "\n";
            } else {
                cout << 2 * max(badL, badR) << "\n";
            }
        }
    }

    return 0;
}
