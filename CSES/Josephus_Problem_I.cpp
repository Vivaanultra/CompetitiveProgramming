#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll len;
    cin >> len;
    vector<ll> a(len);
    iota(a.begin(),a.end(),1);
    bool last_elm_removed = false;
    for(ll i = 0; i < len; i++)
    {
        if(a.size() == 1)
        {
            cout << a[0];
            return 0;
        }
        else
        {
            auto b = a;
            vector<bool> temp(a.size(),true);
            if(last_elm_removed)
            {
                if(a.size() % 2 == 1)
                {
                    last_elm_removed = false;
                }
                for(ll j = 0; j < b.size(); j+=2)
                {
                    temp[j] = false;
                    cout << b[j] << " ";
                }
            }
            else
            {
                if(a.size() % 2 == 1)
                {
                    last_elm_removed = true;
                };
                for(ll j = 1; j < b.size(); j+=2)
                {
                    temp[j] = false;
                    cout << b[j] << " ";
                }
            }
            a.clear();
            for(ll j = 0; j < b.size(); j++)
            {
                if(temp[j])
                {
                    a.push_back(b[j]);
                }
            }
        }
    }
    return 0;
}