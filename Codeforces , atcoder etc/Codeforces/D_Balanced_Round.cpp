#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int problems;
        cin >> problems;
        int difference;
        cin >> difference;
        vector<int> difficulty(problems);
        for (int i = 0; i < problems; i++)
        {
            cin >> difficulty[i];
        }
        sort(difficulty.begin(), difficulty.end());
        int max_problems = 1;
        int current_problems = 1;
        for (int i = 1; i < problems; i++)
        {
            if (difficulty[i] - difficulty[i - 1] <= difference)
            {
                current_problems++;
                max_problems = max(max_problems, current_problems);
            }
            else
            {
                current_problems = 1;
            }
        }
        cout << problems - max_problems << "\n";
    }
}