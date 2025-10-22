#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int n, k, cnt = 0;
    string s;
    cin >> n >> k >> s;
    for(char c : s)
        if(c == '1')
            cnt++;
    cout << (cnt <= k || n < 2*k ? "Alice" : "Bob") << '\n';
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
}