#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll x, y , k;
        cin >> x >> y >> k;
        ll x_moves = x/k;
        ll y_moves = y/k;
        if(x%k != 0)
        {
            x_moves++;
        }
        if(y%k != 0)
        {
            y_moves++;
        }
        if(x_moves > y_moves)
        {
            cout << 2*x_moves -1 << endl;
        }
        else
        {
            cout << 2*y_moves << endl;
        }
    }
    return 0;
}