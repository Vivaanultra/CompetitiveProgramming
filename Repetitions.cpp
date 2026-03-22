#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int cursum = 1;
    int maxsum = 1;
    for(int i = 1; i < s.length(); i++)
    {
        if(s[i] == s[i-1])
        {
            cursum++;
            maxsum = max(maxsum, cursum);
        }
        else
        {
            cursum = 1;
        }
    }
    cout << maxsum << endl;
    return 0;
}