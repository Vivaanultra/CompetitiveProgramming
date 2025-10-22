#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        if (s == "YES" || s == "Yes" || s == "yES" || s == "yeS" || s == "yEs" || s == "YeS" || s == "yEs" || s == "yeS" || s == "YEs" || s == "YEs" || s == "yES" || s == "yEs" || s == "yES" || s == "YeS" || s == "yes")
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}