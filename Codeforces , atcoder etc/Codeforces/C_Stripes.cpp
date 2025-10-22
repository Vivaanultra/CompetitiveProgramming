#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<string> grid(8);
        for (int i = 0; i < 8; i++)
        {
            string s;
            cin >> s;
            grid[i] = s;
        }
        bool found = false;
        for (int i = 0; i < 8; i++)
        {
            if (grid[i] == "RRRRRRRR")
            {
                cout << "R" << endl;
                break;
            }
            if (grid[0][i] == 'B' && grid[1][i] == 'B' && grid[2][i] == 'B' && grid[3][i] == 'B' && grid[4][i] == 'B' && grid[5][i] == 'B' && grid[6][i] == 'B' && grid[7][i] == 'B')
            {
                cout << "B" << endl;
                break;
            }
    }   }
    return 0;
}