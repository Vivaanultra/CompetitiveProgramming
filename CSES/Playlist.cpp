#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(auto &x : a)
    {
        cin >> x;
    }
    ll left = 0;
    ll right = 0;
    ll max_len = 0;
    set<ll> s;
    while(right < n)
    {
        if(s.find(a[right]) == s.end())
        {
            s.insert(a[right]);
            right++;
            max_len = max(max_len , right - left);
        }
        else
        {
            s.erase(a[left]);
            left++;
        }
    }
    cout << max_len << endl;
    return 0;

}