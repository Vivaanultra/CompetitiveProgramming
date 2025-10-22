#include <bits/stdc++.h>
using namespace std;


bool canbeopened(int key, vector<int> arr)
{
    int i = 0;
    if(arr[key-1] == 0)
    {
        return false;
    }
    else
    {
        key = arr[key-1];
    }
    if(arr[key-1] == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int keynum;
        cin >> keynum;
        vector<int> arr(3);
        for (int i = 0; i < 3; i++)
        {
            cin >> arr[i];
        }
        bool yeornon = canbeopened(keynum, arr);
        if(yeornon)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}