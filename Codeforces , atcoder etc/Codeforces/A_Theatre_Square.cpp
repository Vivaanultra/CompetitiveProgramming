#include <iostream>
using namespace std;

int main()
{
    long long int n, m, a;
    cin >> n >> m >> a;
    if(a>=n && a>=m)
    {
        cout << 1;
    }
    else
    {
        long long int x = 1;
        while(a*x < n)
        {
            ++x;
        }
        long long int y = 1;
        while(a*y < m)
        {
            ++y;
        }
        cout << x*y;
    }
}