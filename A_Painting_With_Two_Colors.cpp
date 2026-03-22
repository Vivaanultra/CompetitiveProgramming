#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n , a , b;
        cin >> n >> a >> b;
        bool flag = false;
        if(n%2 == a%2 and a%2 == b%2)
        {
            flag = true;
        }
        if(b > a and b%2 == n%2)
        {
            flag = true;
        }
        cout << (flag ? "YES" : "NO") << "\n";
    }
    return 0;
}