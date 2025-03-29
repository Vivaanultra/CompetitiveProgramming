#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int size = s.size();
    int count = 0;
    for(int i=0;i<size -6;i++)
    {
        if(s[i] == s[i+1] && s[i+1] == s[i+2] && s[i+2] == s[i+3] && s[i+3] == s[i+4] && s[i+4] == s[i+5] && s[i+5] == s[i+6])
        {
            count++;
        }
    }
    if (count > 0)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
}