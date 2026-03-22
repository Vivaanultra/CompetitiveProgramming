#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<pair<ll,ll>> a(n*2);
    for(ll i = 1 ; i <= n ; i++)
    {
        cin >> a[i - 1].first;
        a[i - 1].second = 1;
        cin >> a[i + n - 1].first;
        a[i + n - 1].second = -1;
    }
    sort(a.begin() , a.end());
    ll max_ans = 0;
    ll ans = 0;
    for(int i = 0 ; i < n*2 ; i++)
    {
        ans += a[i].second;
        max_ans = max(max_ans , ans);
    }
    cout << max_ans << endl;
    return 0;


}