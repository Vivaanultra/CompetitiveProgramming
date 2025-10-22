#include <bits/stdc++.h>
using namespace std;
int main()
{
    int nums, letx;
    cin >> nums >> letx;
    vector<int> v(nums);
    for (int i = 0; i < nums; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    if(letx == 0)
    {
        if(v[0] == 1)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << 1 << "\n";
        }
        return 0;
    }
    if(v[letx-1] == v[letx])
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << v[letx-1] << "\n";
    }
    return 0;
}