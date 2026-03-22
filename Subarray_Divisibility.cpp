#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    vector<long long> a(n+1);
    a[0] = 0;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    map<long long,long long> s;
    vector<long long> prefix(n+1, 0);
    long long pref = 0;
    for (long long i = 0; i <= n; i++)
    {
        pref += a[i];
        pref %= n;
        prefix[i] = ((pref % n) + n) % n;
    }
    long long answer = 0;
    for(long long i = 0; i <= n; i++)
    {
        answer += s[prefix[i]];
        s[prefix[i]]++;
    }
    cout << answer << endl;
    return 0;
}