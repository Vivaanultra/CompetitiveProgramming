#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    map<int, int> counts;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        counts[x]++;
    }

    ll ans = 1;
    for(auto const& [val, count] : counts) {
        ans = (ans * (count + 1)) % MOD;
    }

    ans = (ans - 1 + MOD) % MOD;
    
    cout << ans << endl;

    return 0;
}