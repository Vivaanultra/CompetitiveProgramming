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
    int age;
    cin >> age;
    sort(arr, arr + length);
    int total = 0;
    auto it = lower_bound(arr, arr + length, age);
    cout << length - (it - arr);
}