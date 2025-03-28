#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        string s;
        cin >> a >> s;
        int length = a;
        for (int j = 0; j < a; j++)
        {
            if (s[j] == 'B')
            {
                break;
            }
            else
            {
                length--;
            }
        }
        for (int j = a - 1; j >= 0; j--)
        {
            if (s[j] == 'B')
            {
                break;
            }
            else
            {
                length--;
            }
        }
        cout << length << "\n";
    }
}