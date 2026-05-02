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
    ll sum = 0;
    for(int i = 1; i < n; i++)
    {
        if(a[i] > a[i-1])
        {
            continue;
        }
        sum += abs(a[i] - a[i-1]);
        a[i] += abs(a[i] - a[i-1]);
    }
    cout << sum << endl;
}