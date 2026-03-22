#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long sz , k;
    cin >> sz >> k;
    vector<pair<long long,long long>> v(sz);
    for(long long i = 0; i < sz; i++)
    {
        cin >> v[i].first;
        v[i].second = i+1;
    }
    sort(v.begin(),v.end());
    bool flag = false;
    for(long long i = 0; i < sz - 2; i++)
    {
        long long left = i + 1;
        long long right = sz - 1;
        while(left < right)
        {
            long long achived = v[i].first + v[left].first + v[right].first;
            if( achived == k)
            {
                cout << v[i].second << " " << v[left].second << " " << v[right].second << endl;
                flag = true;
                break;
            }
            else if (achived > k)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        if(flag)
        {
            break;
        }
    }
    if(!flag)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;

}