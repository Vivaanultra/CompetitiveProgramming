#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        stack<char> s;
        string str;
        cin >> str;
        for (int i = 0; i < x; i++)
        {
            if (str[i] == '(')
            {
                s.push(str[i]);
            }
            else
            {
                if (!s.empty())
                {
                    s.pop();
                }
            }
        }
        cout << s.size() << "\n";
    }
    return 0;
}