#include <bits/stdc++.h>
using namespace std;

int recursive(int current, int target)
{
    if(current == target)
    {
        return 1;
    }
    if(current > target)
    {
        if(current % 3 == 0)
        {
            return recursive(2*current / 3, target) || recursive(current / 3, target);
        }
        else
        {
            return 0;
        }
    }
    return 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int initial, target;
        cin >> initial >> target;
        if(recursive(initial, target))
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }
    return 0;
}