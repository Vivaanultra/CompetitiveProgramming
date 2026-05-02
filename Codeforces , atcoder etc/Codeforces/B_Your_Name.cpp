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
        string target;
        cin >> s >> target;
        map<char,int> a1;
        map<char,int> a2;
        for(int i = 0; i < len; i++)
        {
            a1[s[i]]++;
            a2[target[i]]++;
        }
        if(a1 == a2)
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }
    return 0;
}