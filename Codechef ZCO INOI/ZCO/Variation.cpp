#include <bits/stdc++.h>
using namespace std;

// this is a perfect solution for a ZCO problm asked in 2015 (november 2014)

int main()
{
    long long int arraylength;
    long long int k;
    cin>>arraylength>>k;
    vector<long long int> array;
    for (long long int i = 0; i < arraylength; i++)
    {
        long long int a;
        cin>>a;
        array.push_back(a);
    }
    sort(array.begin(),array.end());
    long long int count = 0;
    long long int firstelement = array[0];
    long long int minimumelement = k + firstelement;
    long long int in = 1;
    while(array[in] < minimumelement)
    {
        in++;
        
    }
    long long int endsub = arraylength - in;
    for(long long int i = 0; i < arraylength; i++)
    {   
        if(array[in] - array[i] >= k)
        {
            count += endsub;
        }
        else
        {
            while(array[in] - array[i] < k)
            {
                if(endsub == 0)
                {
                    break;
                }
                endsub--;
                in++;
            }
            count += endsub;
        }
    }
    cout << count;


}