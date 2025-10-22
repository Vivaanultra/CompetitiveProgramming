#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num,sub;
    cin >> num >> sub;
    while(sub--)
    {
        if(num%10 == 0)
        {
            num = num/10;
        }
        else
        {
            num--;
        }
    }
    cout << num;
    return 0;
}