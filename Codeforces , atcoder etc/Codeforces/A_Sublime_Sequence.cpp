#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        int n;
        cin >> n;
        if(n%2 == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << x << endl;
        }
    }
    return 0;
}