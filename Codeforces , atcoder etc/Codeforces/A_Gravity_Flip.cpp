#include <bits/stdc++.h>
using namespace std;
int main()
{
    int length;
    cin >> length;
    int arr[length];
    for (int i = 0; i < length; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + length);
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
}