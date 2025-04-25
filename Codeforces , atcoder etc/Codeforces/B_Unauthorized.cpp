#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    int cnt = 0;
    bool login = 0;
    for (int i = 0; i < n; i++)
    {
        if(v[i] == "private" && login == false) cnt++;
        if(v[i] == "login") login = true;
        if(v[i] == "logout") login = false;
    }
    cout << cnt;
}