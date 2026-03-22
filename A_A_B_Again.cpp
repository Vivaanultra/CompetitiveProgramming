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
        int dig1 = s[0] - '0';
        int dig2 = s[1] - '0';
        cout << dig1 + dig2 << "\n";
    }
    return 0;
}