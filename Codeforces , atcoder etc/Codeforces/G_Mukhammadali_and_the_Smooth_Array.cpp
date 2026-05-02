#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
ll len;
vector<ll> a;
vector<ll> c;
vector<ll> dp(len);
ll predp(ll i, ll k)
{
    if(i == 0)
    {
        return 0;
    }
    else
    {
        ll max_return = 0;
        for(int j = 0; j < i; j++)
        {
            if(a[j] <= k)
            {
                max_return = max(max_return, dp[j]);
            }
        }
        return max_return;
    }
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        a.clear();
        c.clear();
        dp.clear();
        cin >> len;
        a.resize(len);
        c.resize(len);
        dp.resize(len);
        for(ll i = 0; i < len; i++)
        {
            cin >> a[i];
        }
        for(ll i = 0; i < len; i++)
        {
            cin >> c[i];
        }
        //now to calculate max dp
        
        dp[0] = c[0];
        for(ll i = 1; i < len; i++)
        {
            dp[i] = c[i] + predp(i,a[i]);
        }
        ll csum = 0;
        for(ll i = 0; i < len; i++)
        {
            csum += c[i];
        }
        cout << csum - *max_element(dp.begin(), dp.end()) << endl;
    }
    return 0;
}