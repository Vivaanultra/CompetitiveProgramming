#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a , b;
        cin >> a >> b;
        if(a == b and b == 1)
        {
            cout << 1 << endl;
            continue;
        }
        cout << max(a,b) - min(a,b) << endl;
    }
    return 0;
}