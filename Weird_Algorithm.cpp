#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    cout << n;
    while(n != 1)
    {
        if(n % 2 == 0)
        {
            n /= 2;
            cout << " " << n;
        }
        else
        {
            cout << " " << 3 * n + 1;
            n = 3 * n + 1;
        }
    }
}