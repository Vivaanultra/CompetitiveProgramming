#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    long long max_val = 0;
    long long sum_val = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        max_val = max(max_val, a[i]);
        sum_val += a[i];
    }

    long long low = max_val;
    long long high = sum_val;
    long long ans = sum_val;

    while(low <= high)
    {
        long long mid = low + (high - low) / 2;
        
        int partitions = 1;
        long long current_sum = 0;

        for(int i = 0; i < n; i++)
        {
            if(current_sum + a[i] > mid)
            {
                partitions++;
                current_sum = a[i];
            }
            else
            {
                current_sum += a[i];
            }
        }

        if(partitions <= k)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}