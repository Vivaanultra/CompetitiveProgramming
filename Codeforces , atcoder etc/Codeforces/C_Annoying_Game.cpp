#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long l , k;
        cin >> l >> k;
        vector<long long> arr(l);
        vector<long long> b(l);
        for (long long i = 0; i < l; i++)
        {
            cin >> arr[i];
        }
        for (long long i = 0; i < l; i++)
        {
            cin >> b[i];
        }
        k = k%2;
        if(k==0)
        {   
            long long cur_max = arr[0];
            long long max_overall = arr[0];
            for(long long i = 1; i < l; i++)
            {
                cur_max = max(arr[i], cur_max + arr[i]);
                max_overall = max(max_overall, cur_max);
            }
            cout << max_overall << endl;
            continue;
        }
        else
        {
            vector<long long> dp1(l);
            vector<long long> dp2(l);
            vector<long long> score(l);
            dp1[0] = arr[0];
            dp2[0] = arr[l-1];
            for(long long i = 1; i < l; i++)
            {
                dp1[i] = max(arr[i], dp1[i-1] + arr[i]);
            }
            vector<long long> rev = arr;
            reverse(rev.begin(), rev.end());
            for(long long i = 1; i < l; i++)
            {
                dp2[i] = max(rev[i], dp2[i-1] + rev[i]);
            }
            reverse(dp2.begin(), dp2.end());
            for(long long i = 0; i < l; i++)
            {
                score[i] = dp1[i] + dp2[i] + b[i] - arr[i];
            }
            cout << *max_element(score.begin(), score.end()) << endl;
            continue;
        }
    }
    return 0;
}