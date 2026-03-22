#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n , x;
    cin >> n >> x;
    vector<long long> v(n);
    for(auto &x : v)
    {
        cin >> x;
    }
    long long prefix = 0;
    map<long long,long long> mp;
    long long answer = 0;
    mp[0] = 1;
    for(long long i = 0; i < n; i++)
    {
        prefix += v[i];
        answer += mp[prefix - x];
        mp[prefix]++;
    }
    cout << answer;


}