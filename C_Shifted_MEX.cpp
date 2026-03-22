#include <bits/stdc++.h>
using namespace std;
int main()
{
    int INF = 1e9 + 7;
    int t;
    cin >> t;
    while (t--)
    {
        int len;
        cin >> len;
        vector<int> a(len);
        for (int i = 0; i < len; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<int> b;
        b.push_back(a[0]);
        for(int i = 1; i < len; i++)
        {
            if(a[i] != a[i-1])
            {
                b.push_back(a[i]);
            }
        }
        int ans = 1;
        int l = 0;
        int r = 1;
        while (r < b.size())
        {
            if(abs(b[r] - b[r-1]) == 1)
            {
                ans = max(ans, r - l + 1);
                r++;
            }
            else
            {
                l = r;
                r++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}