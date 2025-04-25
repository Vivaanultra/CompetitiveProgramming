#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; i++)
    {
        int candidates;
        cin >> candidates;
        int totalvotes = 0;
        int maxvotes = 0;
        int winner = 0;
        bool duplicate_max = false;
        
        for (int j = 0; j < candidates; j++)
        {
            int votes;
            cin >> votes;
            totalvotes += votes;
            if (votes > maxvotes)
            {
                maxvotes = votes;
                winner = j + 1;
                duplicate_max = false;
            }
            else if (votes == maxvotes)
            {
                duplicate_max = true;
            }
        }
        
        if (duplicate_max)
        {
            cout << "no winner" << endl;
        }
        else if (maxvotes > totalvotes / 2)
        {
            cout << "majority winner " << winner << endl;
        }
        else if (maxvotes <= totalvotes / 2)
        {
            cout << "minority winner " << winner << endl;
        }
    }
}