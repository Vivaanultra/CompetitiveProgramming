#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        string t;
        cin >> s >> t;
        bool flag = false;
        int sz = t.size();
        int count = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != '?')
            {
                if(!flag)
                {
                    if(s[i] == t[count])
                    {
                        count++;
                        if(count == sz)
                        {
                            flag = true;
                        }
                    }
                }
            }
            else
            {
                if(!flag)
                {
                    s[i] = t[count];
                    count++;
                    if(count == sz)
                    {
                        flag = true;
                    }
                }
                else
                {
                    s[i] = 'a';
                }
            }
        }
        if(flag)
        {
            cout << "YES" << "\n" << s << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }
    return 0;
}