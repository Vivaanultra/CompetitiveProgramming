#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    if (s.size() == 1)
    {
        cout << s;
    }
    else
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '+')
            {
                s.erase(i, 1);  // 1 specifies to remove exactly one character at position i
            }
        }
        sort(s.begin(), s.end());
        for (int i = 0; i < s.size(); i++)
        {
            cout << s[i];
            if (i != s.size() - 1)
            {
                cout << '+';
            }
        }
    }
}