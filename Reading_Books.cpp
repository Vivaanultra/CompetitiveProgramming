#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    vector<long long> v(n);
    for(auto &x : v)
    {
        cin >> x;
    }
    long long sum = 0;
    for(auto x : v)
    {
        sum += x;
    }
    long long mx = *max_element(v.begin(),v.end());
    if(sum - mx < mx)
    {
        long long waiting_time = mx - (sum - mx);
        cout << sum + waiting_time << endl;
    }
    else
    {
        cout << sum << endl;
    }
}