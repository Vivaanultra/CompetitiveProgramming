#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int count = 0;
    while (t--)
    {
        int a , b;
        cin >> a >> b;
        if (b > a)
        {
            count++;
        }
    }
    cout << count << "\n";
    return 0;
}