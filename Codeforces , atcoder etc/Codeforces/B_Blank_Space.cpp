#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int length;
        cin >> length;
        int count = 0;
        int localcount = 0;
        for (int i = 0; i < length; i++)
        {
            int temp;
            cin >> temp;
            if (temp == 0)
            {
                localcount++;
                count = max(count, localcount);
            }
            else
            {
                localcount = 0;
            }
        }
        cout << count << "\n";
    }
    return 0;
}