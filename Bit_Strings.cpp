#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    long long sum = 1;
    while(n--)
    {
        sum = (sum%1000000007 * 2)%1000000007;
    }
    cout << sum << endl;
    return 0;
}