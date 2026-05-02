#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
       ll n;
       cin >> n;
       vector<ll> a(n);
       vector<ll> b(n);
       for(ll i = 0; i < n; i++)
       {
           cin >> a[i];
       }
       for(ll i = 0; i < n; i++)
       {
           cin >> b[i];
       }
       vector<ll> dp_min(n);
       vector<ll> dp_max(n);
       dp_min[0] = min(-a[0],b[0]);
       dp_max[0] = max(-a[0],b[0]);
       for(ll i = 1; i < n; i++)
       {
           vector<ll> pb;
           pb.push_back(dp_min[i-1] - a[i]);
           pb.push_back(dp_max[i-1] - a[i]);
           pb.push_back(b[i] - dp_min[i-1]);
           pb.push_back(b[i] - dp_max[i-1]);
           dp_min[i] = *min_element(pb.begin(), pb.end());
           dp_max[i] = *max_element(pb.begin(), pb.end());
       }
       cout << dp_max[n-1] << endl;
    }
    return 0;
}