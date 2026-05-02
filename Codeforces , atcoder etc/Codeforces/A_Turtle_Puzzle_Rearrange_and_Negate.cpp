#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int len;
        cin >> len;
        vector<int> v(len);
        for (int i = 0; i < len; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int idx = lower_bound(v.begin(), v.end(), 0) - v.begin();
        for (int i = 0; i < idx; i++)
        {
            v[i] = -v[i];
        }
        int sum = 0;
        for (int i = 0; i < len; i++)
        {
            sum += v[i];
        }
        cout << sum << endl;
    }
    return 0;
}