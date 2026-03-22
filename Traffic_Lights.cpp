#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll streetlen, lig;
    cin >> streetlen >> lig;

    set<ll> lights;
    lights.insert(0);
    lights.insert(streetlen);

    multiset<ll> dis;
    dis.insert(streetlen);

    for(ll i = 0; i < lig; i++)
    {
        ll temp;
        cin >> temp;

        auto it = lights.upper_bound(temp);
        ll right = *it;
        it--;
        ll left = *it;

        dis.erase(dis.find(right - left));
        dis.insert(right - temp);
        dis.insert(temp - left);
        lights.insert(temp);

        cout << *dis.rbegin() << " ";
    }
    return 0;
}