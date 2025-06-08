#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        if (isupper(s[i]))
                    a++;
                else
                    b++;
        
    }
    if (a > b)
    {
        for (int i = 0; i < n; i++)
        {
            s[i] = toupper(s[i]);
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            s[i] = tolower(s[i]);
        }
    }
    cout << s;
}