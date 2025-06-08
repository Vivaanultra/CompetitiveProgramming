#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int first_closed = -1, last_closed = -1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 1)
            {
                if (first_closed == -1)
                    first_closed = i;
                last_closed = i;
            }
        }
        if (last_closed - first_closed + 1 <= x)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}