#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int uid(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }
ll uld(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(rng); }
*/
void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> freq(n + 1);
    for (int x : a) freq[x]++;

    vector<int> len(n + 1);
    len[0] = freq[a[0]] == 1;
    for (int i = 1; i < n; i++)
        if (freq[a[i]] == 1)
            len[i] = len[i - 1] + 1;
    
    int mx = *max_element(len.begin(), len.end());
    if (mx == 0){
        cout << "0\n";
        return;
    }

    for (int i = 0; i < n; i++){
        if (len[i] == mx){
            cout << i - len[i] + 2 << " " << i + 1 << "\n";
            return;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) solve();
}
