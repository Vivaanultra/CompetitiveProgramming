#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int length;
        cin >> length;
        vector<int> v(length);
        for (int i = 0; i < length; i++)
        {
            v[i] = i + 1;
        }
        if(length %2 == 0)
        {
            cout << -1 << "\n";
        }
        else
        {
            for (int i = 0; i < length; i++)
            {
                cout << length - v[i] + 1 << " ";
            }
            cout << "\n";
        }

    }
}
