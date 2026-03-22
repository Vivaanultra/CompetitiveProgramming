#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin >> n;
    vector<pair<ll,ll>> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i].second >> v[i].first;
    }
    sort(v.begin(),v.end());
    ll ans = 0;
    ll prev_end_time = 0;
    for(int i=0;i<n;i++)
    {
        if(v[i].second >= prev_end_time)
        {
            ans++;
            prev_end_time = v[i].first;
        }
    }
    cout << ans << endl;
    return 0;
}