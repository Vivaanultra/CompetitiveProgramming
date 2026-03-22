#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int len , sum , x;
        cin >> len >> sum >> x;
        int over = 0;
        while(len--)
        {
            int f;
            cin >> f;
            over += f;
        }
        if(over > sum)
        {
            cout << "NO" << endl;
        }
        else if(over == sum)
        {
            cout << "YES" << endl;
        }
        else
        {
            if((sum - over) % x == 0)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        
    }
    return 0;
}