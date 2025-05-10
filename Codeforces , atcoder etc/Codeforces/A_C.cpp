#include <bits/stdc++.h>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(max(a,b) > c)
        {
            cout << 0 << '\n';
            continue;
        } 
        if(a > b)
        {
            swap(a,b);
        }
        int count = 0;
        while(max(a,b) <= c)
        {
            a += b;
            if(a > b)
            {
                swap(a,b);
            }
            count++;
        }
        cout << count << '\n';
    }
}