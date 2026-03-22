#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll sz;
    cin >> sz;
    vector<ll> a(sz);
    for(ll i=0;i<sz;i++)
    {
        cin >> a[i];
    }
    ll l = 0;
    ll r = 0;
    ll ans = 0 ;
    set<ll> s;
    while(r < sz)
    {
        if(s.find(a[r]) == s.end())
        {
            s.insert(a[r]);
            ans += (r - l + 1);
            r++;
        }
        else
        {
            s.erase(a[l]);
            l++;
        }
    }
    cout << ans << endl;
    return 0;

}