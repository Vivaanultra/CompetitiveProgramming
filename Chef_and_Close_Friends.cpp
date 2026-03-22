#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x , y , z;
        cin >> x >> y >> z;
        if(z > y)
        {
            cout << 2*y << "\n";
        }
        else
        {
            cout << 2*z << "\n";
        }
    }
    return 0;
}