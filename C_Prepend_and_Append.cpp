#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int len;
        cin >> len;
        string s;
        cin >> s;
        int sz = s.size();
        int l = 0;
        int r = sz - 1;
        while(l < r)
        {
            if(s[l] != s[r])
            {
                sz -= 2;
                l++;
                r--;
                continue;
            }
            break;
        }
        cout << sz << "\n";
    }
    return 0;
}