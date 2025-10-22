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
        vector<int> a(len);
        int zeros = 0;
        int minuses = 0;
        for(int i = 0; i < len; i++)
        {
            cin >> a[i];
            if(a[i] == 0)
            {
                zeros++;
            }
            else if(a[i] < 0)
            {
                minuses++;
            }
        }
        if(minuses%2 != 0)
        {
            zeros = zeros + 2;
        }
        cout << zeros << "\n";
    }
    return 0;
}