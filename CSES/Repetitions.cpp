#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int best = 1;
    int current = 1;
    if(s.size() == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            current ++;
            best = max(best, current);
        }
        else
        {
            current  = 1;
        }
    }
    cout << best << endl;
}