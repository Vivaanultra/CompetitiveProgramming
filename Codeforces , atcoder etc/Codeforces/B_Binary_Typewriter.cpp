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
        string s;
        cin >> n >> s;

        // 1) base cost
        ll presses = n;
        ll init_move = (s[0] == '1');
        ll trans = 0;
        for(int i = 1; i < n; i++){
            if(s[i] != s[i-1]) trans++;
        }
        ll base = presses + init_move + trans;

        // 2) count “01” and “10”
        int c01 = 0, c10 = 0;
        for(int i = 1; i < n; i++){
            if(s[i-1]=='0' && s[i]=='1') c01++;
            if(s[i-1]=='1' && s[i]=='0') c10++;
        }

        // 3) compute best saving b in {0,1,2}
        int b = 0;
        // full general case or bring a 0 to front if s[0]=='1'
        if(c01 >= 2 || c10 >= 2) {
            b = 2;
        } else if(s[0]=='1' && c01 >= 1) {
            // you can reverse from front to the first '01' to kill two moves
            b = 2;
        }

        if(b < 2) {
            // maybe a single‐move gain on the right end
            if(s[n-1]=='0' && c01 >= 1)  b = max(b, 1);
            if(s[n-1]=='1' && c10 >= 1)  b = max(b, 1);
            // or by reversing the entire string if s1=1, sn=0
            if(s[0]=='1' && s[n-1]=='0') b = max(b, 1);
        }

        cout << (base - b) << "\n";
    }

    return 0;
}
