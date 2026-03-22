#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long sz;
    cin >> sz;
    long long sum = 0;
    for(long long i = 0; i < sz - 1; i++)
    {
        long long x;
        cin >> x;
        sum += x;
    }
    cout << (sz * (sz+1))/2 - sum << endl;
    return 0;
}