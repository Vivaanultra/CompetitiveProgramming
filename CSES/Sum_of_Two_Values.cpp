#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll count , x;
    cin >> count >> x;
    map<ll,ll> mp;
    for(int i = 0 ; i < count ; i++)
    {
        ll temp;
        cin >> temp;
        
        if(mp.find(x - temp) != mp.end())
        {
            cout << mp[x - temp] + 1 << " " << i + 1 << endl;
            return 0;
        }
        mp[temp] = i;
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;

}