#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll chil , weig;
    cin >> chil >> weig;
    vector<ll> a(chil);
    for(ll i = 0 ; i < chil ; i++)
    {
        cin >> a[i];
    }
    sort(a.begin() , a.end());
    ll chilp = 0;
    ll l = 0;
    ll r = chil - 1;
    while(l < r)
    {
        if(a[l] + a[r] <= weig)
        {
            chilp += 2;
            l++;
            r--;
        }
        else
        {
            r--;
        }
    }
    cout << chilp/2 + chil - chilp << endl;
    return 0;
}