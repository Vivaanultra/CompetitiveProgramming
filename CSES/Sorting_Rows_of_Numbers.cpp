#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    t++;
    vector<string> v;
    while (t--)
    {
        string s;
        getline(cin, s);
        s = s.substr(0, s.length() - 2);    
        v.push_back(s); 
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\n";
    }


}