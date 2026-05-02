#include <bits/stdc++.h>
using namespace std;
int main()
{
    int l;
    cin >> l;
    if(l < 4)
    {
        if(l == 1)
        {
            cout << 1 << endl;
            return 0;
        }
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    for(int i = l; i >= 1; i--)
    {
        if(i%2 != 0)
        {
            cout << i << " ";
        }
    }
    for(int i = l; i >= 1; i--)
    {
        if(i%2 == 0)
        {
            cout << i << " ";
        }
    }
}