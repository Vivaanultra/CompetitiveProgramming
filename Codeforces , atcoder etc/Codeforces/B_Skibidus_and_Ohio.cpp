#include <bits/stdc++.h>
using namespace std;

void solve(string s, int &len)
{
    int dupe = 0;
    for(int i = 0; i < len; i++)
    {
        if(s[i] == s[i+1])
        {
            dupe++;
            s.erase(i+1);
            len--;
            if(i == 0 && i + 1 < len)
            {
                s[i] = s[i + 1];                
            }
            else if(i > 0)
            {
                s[i] = s[i - 1];
            }
            else
            {
                s[i] = 'a';
            }
            break;
        }
    }
    if(dupe == 0)
    {
        cout << len << "\n";
    }
    else
    {
        solve(s, len);
    }
}

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        string s;
        cin >> s;
        int len = s.length();
        solve(s, len);
    }
}