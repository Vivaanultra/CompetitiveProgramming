#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int p;
        cin >> p;
        int y , r;
        cin >> y >> r;
        cout << min(p,(y/2 + r)) << "\n";
    }
    return 0;
}