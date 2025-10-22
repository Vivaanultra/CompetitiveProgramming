#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int length;
        cin >> length;
        int arr[length];
        for (int i = 0; i < length; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + length);
        bool valid = true;
        for (int i = 0; i < length - 1; i++)
        {
            if(arr[i] == arr[i+1])
            {
                valid = false;
                break;
            }
        }
        if(valid)
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