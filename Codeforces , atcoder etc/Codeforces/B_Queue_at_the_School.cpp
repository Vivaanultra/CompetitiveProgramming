#include <bits/stdc++.h>
using namespace std;
int main()
{
    int length, time;
    cin >> length >> time;
    string s;
    cin >> s;
    while(time--)
    {
        for(int i = 0; i < length - 1; i++)
        {
            if(s[i] == 'B' && s[i + 1] == 'G')
            {
                swap(s[i], s[i + 1]);
                i++;
            }
        }
    }
    cout << s << endl;
}