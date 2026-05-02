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
        if(a > b)
        {
            swap(a,b);
        }
        if((a + b) % 3 == 0 && !(b > 2*a))
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }
    return 0;
}