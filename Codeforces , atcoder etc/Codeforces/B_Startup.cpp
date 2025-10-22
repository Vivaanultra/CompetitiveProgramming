#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int shelves , bottles;
        cin >> shelves >> bottles;
        vector<int> v(bottles, 0);
        for(int i = 0; i < bottles; i++)
        {
            int brand , cost;
            cin >> brand >> cost;
            v[brand - 1] += cost;
        }
        if(bottles - shelves >= 0)
        {
            sort(v.begin(),v.end());
            int ans = 0;
            for(int i = bottles - shelves; i < bottles; i++)
            {
                ans += v[i];
            }
            cout << ans << endl;
        }
        else
        {
            int ans = 0;
            for(int i = 0; i < bottles; i++)
            {
                ans += v[i];
            }
            cout << ans << endl;
        }
    }
    return 0;
}