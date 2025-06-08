#include <bits/stdc++.h>
using namespace std;
//AI generated code
int main()
{
    int rotations;
    cin >> rotations;
    vector<int> lock(rotations);
    for (int i = 0; i < rotations; i++)
    {
        cin >> lock[i];
    }
    bool possible = false;
        for (int mask = 0; mask < (1 << rotations); mask++)
        {
            int sum = 0;
            for (int i = 0; i < rotations; i++)
            {
                if (mask & (1 << i))
                {
                    sum += lock[i];
                }
                else
                {
                    sum -= lock[i];
                }
            }
            if (sum % 360 == 0)
            {
                possible = true;
                break;
            }
        }
        cout << (possible ? "YES" : "NO") << endl;
    
}