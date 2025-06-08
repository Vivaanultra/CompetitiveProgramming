#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<long long int> v;
    vector<long long int> vsort;
    long long int length;
    cin >> length;
    v.resize(length);
    vsort.resize(length);
    vector<long long int> prefix_sum(length + 1, 0);
    vector<long long int> sorted_prefix_sum(length + 1, 0);
    
    for (long long int i = 0; i < length; i++)
    {
        cin >> v[i];
        vsort[i] = v[i];
        prefix_sum[i + 1] = prefix_sum[i] + v[i];
    }
    
    sort(vsort.begin(), vsort.end());
    for(long long int i = 0; i < length; i++) {
        sorted_prefix_sum[i + 1] = sorted_prefix_sum[i] + vsort[i];
    }
    
    long long int q;
    cin >> q;
    for (long long int i = 0; i < q; i++)
    {
        long long int type, l, r;
        cin >> type >> l >> r;
        if (type == 1)
        {
            cout << prefix_sum[r] - prefix_sum[l-1] << endl;
        } 
        else if(type == 2)
        {
            cout << sorted_prefix_sum[r] - sorted_prefix_sum[l-1] << endl;
        }
    }
}