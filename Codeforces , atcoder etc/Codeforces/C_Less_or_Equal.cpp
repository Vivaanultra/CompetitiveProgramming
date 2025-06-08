#include <bits/stdc++.h>
using namespace std;
int main()
{
    int length , k;
    cin >> length >> k;
    vector<int> v(length);
    for (int i = 0; i < length; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    if(k == 0)
    {
        if(v[0] == 1)
        {
            cout << "-1 ";
            return 0;
        }
        if(v[0] != 1)
        {
            cout << 1;
            return 0;
        }
    }
    if(v[k] == v[k-1])
    {
        cout << "-1 ";
        return 0;
    }
    if(v[k] != v[k-1])
    {
        cout << v[k - 1];
        return 0;
    }
}