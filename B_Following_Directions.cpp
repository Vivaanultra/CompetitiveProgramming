#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x = 0, y = 0;
        int count;
        cin >> count;
        bool flag = true;
        string s;
        cin >> s;
        for(int i = 0; i < count; i++)
        {
            char c = s[i];
            if(c == 'L')
            {
                x--;
            }
            else if(c == 'R')
            {
                x++;
            }
            else if(c == 'U')
            {
                y++;
            }
            else
            {
                y--;
            }
            if(x == y and y == 1)
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            cout << "NO" << "\n";
        }
        else
        {
            cout << "YES" << "\n";
        }
    }
    return 0;
}