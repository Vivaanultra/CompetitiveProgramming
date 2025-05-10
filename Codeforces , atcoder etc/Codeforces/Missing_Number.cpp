#include <bits/stdc++.h>
using namespace std;
int main()
{
    int length;
    cin >> length;
    vector<int> arr(length - 1);
    for(int i = 0; i < length - 1; i++)
    {
        int x;
        cin >> x;
        arr[i] = x;
    }
    sort(arr.begin(), arr.end());
    for(int i = 0; i < length; i++)
    {
        if(arr[i] != i + 1)
        {
            cout << i + 1;
            break;
        }
    }
}    
