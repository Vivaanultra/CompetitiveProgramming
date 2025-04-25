#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        string s;
        cin >> s;
        int len = s.length();
        s.erase(len-1);
        s[len - 2] = 'i';
        cout << s << "\n";
    }
}