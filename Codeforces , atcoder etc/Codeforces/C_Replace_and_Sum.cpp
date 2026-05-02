#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin >> t;
    while (t--)
    {
        long long n , q;
        cin >> n >> q;
        vector<long long> a(n);
        vector<long long> b(n);
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (long long i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        a[n-1] = max (a[n-1] , b[n-1]);
        for(long long i = n-2 ; i >= 0 ; i--)
        {
            a[i] = max({a[i] , a[i+1], b[i]});
        }
        vector<long long> ans(n + 1);
        ans[0] = 0;
        long long cur = 0;
        for (long long i = 0; i < n; i++)
        {
            cur += a[i];
            ans[i+1] = cur;
        }
        for (long long i = 0; i < q; i++)
        {
            long long l , r;
            cin >> l >> r;
            cout << ans[r] - ans[l-1] << " ";
        }
        cout << endl;
    }
    return 0;
}