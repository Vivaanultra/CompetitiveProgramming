#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long mach , prod;
    cin >> mach >> prod;
    vector<long long> mt(mach);
    for(long long i = 0; i < mach; i++)
    {
        cin >> mt[i];
    }
    sort(mt.begin(),mt.end());
    long long lb = 0;
    long long ub = 1e18;
    while(lb < ub)
    {
        long long mid = (lb + ub)/2;
        long long cnt = 0;
        for(long long i = 0; i < mach; i++)
        {
            cnt += mid/mt[i];
            if (cnt >= prod)
            {
                break;
            }
        }
        if(cnt >= prod)
        {
            ub = mid;
        }
        else
        {
            lb = mid + 1;
        }
    }
    cout << ub << endl;
    return 0;
}