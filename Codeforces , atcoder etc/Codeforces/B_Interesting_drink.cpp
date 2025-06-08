#include <bits/stdc++.h>
using namespace std;
int main()
{
    int length;
    cin >> length;
    int arr[length];
    for(int i = 0; i < length; i++)
    {
        cin >> arr[i];
    }
    int queries;
    cin >> queries;
    sort(arr, arr + length);
    while(queries--)
    {
        int money;
        cin >> money;
        cout << upper_bound(arr, arr + length, money) - arr << "\n";
    }
}