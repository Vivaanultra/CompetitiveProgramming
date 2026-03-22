#include <bits/stdc++.h>
using namespace std;

int solve(int a1, int a2, int a3, int a4, int a5) {
    int cnt = 0;
    if (a3 == a1 + a2) cnt++;
    if (a4 == a2 + a3) cnt++;
    if (a5 == a3 + a4) cnt++;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int a1, a2, a4, a5;
        cin >> a1 >> a2 >> a4 >> a5;
        
        int ans = 0;
        ans = max(ans, solve(a1, a2, a1 + a2, a4, a5));
        ans = max(ans, solve(a1, a2, a4 - a2, a4, a5));
        ans = max(ans, solve(a1, a2, a5 - a4, a4, a5));
        
        cout << ans << "\n";
    }
    return 0;
}