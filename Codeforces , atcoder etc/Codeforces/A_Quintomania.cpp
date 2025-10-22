#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        bool flag = true;
        for (int i = 0; i < n - 1; i++)
        {
            if(abs(a[i] - a[i+1]) == 5 or abs(a[i] - a[i+1]) == 7)
            {
                continue;
            }
            flag = false;
            break;
        }
        if (flag)
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