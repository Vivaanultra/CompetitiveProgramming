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
        int cur_max = v[0];
        int count = 0;
        for(int i = 1; i < len; i ++)
        {
            if(v[i] >= cur_max)
            {
                cur_max = v[i];
            }
            else
            {
                count++;
            }
        }
        cout << count << "\n";
    }
    return 0;
}