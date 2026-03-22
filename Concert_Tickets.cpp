#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll tick , cust;
    cin >> tick >> cust;
    vector<ll> a(tick);
    vector<ll> b(cust);
    for(ll i = 0 ; i < tick ; i++)
    {
        cin >> a[i];
    }
    for(ll i = 0 ; i < cust ; i++)
    {
        cin >> b[i];
    }
    sort(a.begin() , a.end());
    multiset<ll> s;
    for(ll i = 0 ; i < tick ; i++)
    {
        s.insert(a[i]);
    }
    for(ll i = 0; i < cust; i++)
    {
        if(s.empty())
        {
            cout << -1 << endl;
        }
        else
        {
            auto it = s.upper_bound(b[i]);
            if(it == s.begin())
            {
                cout << -1 << endl;
            }
            else
            {
                it--;
                cout << *it << endl;
                s.erase(it);
            }
        }
    }
}