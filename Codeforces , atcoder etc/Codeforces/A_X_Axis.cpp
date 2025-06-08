#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int arr[3];
        cin >> arr[0];
        cin >> arr[1];
        cin >> arr[2];
        sort(arr, arr + 3);
        {
            cout << arr[2] - arr[0] << "\n";
        }
    }
    return 0;
}