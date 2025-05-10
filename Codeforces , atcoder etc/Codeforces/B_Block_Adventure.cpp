#include <bits/stdc++.h>
using namespace std;

/*
number of columns, number of items in bag and jump height.                                                                                                           
remove like every single one and add to M so that no loop is required.
then just subtract the number of items from M if the jump height isnt possible.                                                                   
if at any point M goes to negative (check after jump) then abort and cout No.
If you make it to the end then cout Yes.
*/
int main()
{
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int total = m;
        bool flag = true;
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] >= arr[i + 1] - k)
            {
                total += arr[i] - max(0, arr[i + 1] - k);
            
            }
            else
            {
                total -= arr[i + 1] - arr[i] - k;
                if (total < 0)
                {
                    flag = false;
                }
            }
        }
        cout << (flag ? "YES" : "NO") << "\n";
    }
} //YES THIS CODE DOES WHAT THE COMMENTS DESCRIBE